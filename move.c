#include "move.h"

#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

#include "dungeon.h"
#include "heap.h"
#include "move.h"
#include "npc.h"
#include "pc.h"
#include "character_t.h"
#include "Character.hpp"
#include "utils.h"
#include "path.h"
#include "event.h"
#include "io.h"

void do_combat(dungeon_t *d, Character *atk, Character *def)
{
  if (!atk) { printf("NULL ATK IN move.c:21:do_combat\n"); fflush( stdout ); }
  if (!def) { printf("NULL DEF IN move.c:22:do_combat\n"); fflush( stdout ); }
  set_alive(def,0);
  if (def != d->pc) {
    d->num_monsters--;
  }
}

void move_character(dungeon_t *d, Character *c, pair_t next)
{
  int cy = get_character_position_y(c);
  int cx = get_character_position_x(c);
  if (charpair(next) && ((next[dim_y] != cy ) || (next[dim_x] != cx ))) {
    if (charpair(next)) {
      printf("Attack from: y= %d, x= %d - ", cy, cx);
      printf("    Died at: y= %d, x= %d\n", next[dim_y], next[dim_x]); fflush( stdout );
    }
    
    do_combat(d, c, charpair(next));
  }

  d->character[cy][cx] = NULL;
  set_character_position_y(c, next[dim_y]);
  set_character_position_x(c, next[dim_x]);
  d->character[cy][cx] = c;
}

void do_moves(dungeon_t *d)
{
  pair_t next;
  Character *c = NULL;
  event_t *e;

  /* Remove the PC when it is PC turn.  Replace on next call.  This allows *
   * use to completely uninit the heap when generating a new level without *
   * worrying about deleting the PC.                                       */

  if (pc_is_alive(d)) {
    /* The PC always goes first one a tie, so we don't use new_event().  *
     * We generate one manually so that we can set the PC sequence       *
     * number to zero.                                                   */
    e = malloc(sizeof (*e));
    e->type = event_character_turn;
    /* The next line is buggy.  Monsters get first turn before PC.  *
     * Monster gen code always leaves PC in a monster-free room, so *
     * not a big issue, but it needs a better solution.             */
    /* 1.05: I'm still trying to figure out what the right solution *
     * to this is.  I've come up with several ugly hacks that fix   *
     * it, but there must be a better way...                        */
    e->time = d->time + (1000 / 10); //get_speed(d->pc) //PC speed is 10. weird 0 errors
    e->sequence = 0;
    e->c = d->pc;
    heap_insert(&d->events, e);
  }

  while (pc_is_alive(d) &&
         (e = heap_remove_min(&d->events)) &&
         ((e->type != event_character_turn) || (e->c != d->pc))) {
    d->time = e->time;
    if (e->type == event_character_turn) {
      c = e->c;
    }
    if (!is_alive(c)) {
      if (d->character[get_character_position_y(c)][get_character_position_x(c)] == c) {
        d->character[get_character_position_y(c)][get_character_position_x(c)] = NULL;
      }
      if (c != d->pc) {
        event_delete(e);
      }
      continue;
    }

    npc_next_pos(d, c, next);
    move_character(d, c, next);

    heap_insert(&d->events, update_event(d, e, 1000 / get_speed(c)));
  }

  io_display(d);
  if (pc_is_alive(d) && e->c == d->pc) {
    c = e->c;
    d->time = e->time;
    /* Kind of kludgey, but because the PC is never in the queue when   *
     * we are outside of this function, the PC event has to get deleted *
     * and recreated every time we leave and re-enter this function.    */
    e->c = NULL;
    event_delete(e);

    io_handle_input(d);
  }
}

void dir_nearest_wall(dungeon_t *d, Character *c, pair_t dir)
{
  dir[dim_x] = dir[dim_y] = 0;

  if (get_character_position_x(c) != 1 && get_character_position_x(c) != DUNGEON_X - 2) {
    dir[dim_x] = (get_character_position_x(c) > DUNGEON_X - get_character_position_x(c) ? 1 : -1);
  }
  if (get_character_position_y(c) != 1 && get_character_position_y(c) != DUNGEON_Y - 2) {
    dir[dim_y] = (get_character_position_y(c) > DUNGEON_Y - get_character_position_y(c) ? 1 : -1);
  }
}

uint32_t in_corner(dungeon_t *d, Character *c)
{
  uint32_t num_immutable;

  num_immutable = 0;

  num_immutable += (mapxy(get_character_position_x(c) - 1,
                          get_character_position_y(c)    ) == ter_wall_immutable);
  num_immutable += (mapxy(get_character_position_x(c) + 1,
                          get_character_position_y(c)    ) == ter_wall_immutable);
  num_immutable += (mapxy(get_character_position_x(c)    ,
                          get_character_position_y(c) - 1) == ter_wall_immutable);
  num_immutable += (mapxy(get_character_position_x(c)    ,
                          get_character_position_y(c) + 1) == ter_wall_immutable);

  return num_immutable > 1;
}

static void new_dungeon_level(dungeon_t *d, uint32_t dir)
{
  /* Eventually up and down will be independantly meaningful. *
   * For now, simply generate a new dungeon.                  */

  switch (dir) {
  case '<':
  case '>':
    new_dungeon(d);
    break;
  default:
    break;
  }
}

uint32_t move_pc(dungeon_t *d, uint32_t dir)
{
  pair_t next;
  uint32_t was_stairs = 0;

  next[dim_y] = get_character_position_y(d->pc);
  next[dim_x] = get_character_position_x(d->pc);

  switch (dir) {
  case 1:
  case 2:
  case 3:
    next[dim_y]++;
    break;
  case 4:
  case 5:
  case 6:
    break;
  case 7:
  case 8:
  case 9:
    next[dim_y]--;
    break;
  }
  switch (dir) {
  case 1:
  case 4:
  case 7:
    next[dim_x]--;
    break;
  case 2:
  case 5:
  case 8:
    break;
  case 3:
  case 6:
  case 9:
    next[dim_x]++;
    break;
  case '<':
    if (mappair(*get_pair_t(d->pc)) == ter_stairs_up) {
      was_stairs = 1;
      new_dungeon_level(d, '<');
    }
    break;
  case '>':
    if (mappair(*get_pair_t(d->pc)) == ter_stairs_down) {
      was_stairs = 1;
      new_dungeon_level(d, '>');
    }
    break;
  }

  if (was_stairs) {
    return 0;
  }

  if ((dir != '>') && (dir != '<') && (mappair(next) >= ter_floor)) {
    move_character(d, d->pc, next);
    dijkstra(d);
    dijkstra_tunnel(d);

    return 0;
  }

  return 1;
}
