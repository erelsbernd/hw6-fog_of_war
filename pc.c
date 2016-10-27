#include <stdlib.h>

#include "string.h"

#include "dungeon.h"
#include "pc.h"
#include "utils.h"
#include "move.h"
#include "path.h"

void pc_delete(pc_t *pc)
{
  if (pc) {
    free(pc);
  }
}

uint32_t pc_is_alive(dungeon_t *d)
{
  return is_alive(d->pc);
}

void place_pc(dungeon_t *d)
{
  
  int range_y = rand_range(d->rooms->position[dim_y],
                          (d->rooms->position[dim_y] +
                           d->rooms->size[dim_y] - 1));
  int range_x = rand_range(d->rooms->position[dim_x],
                          (d->rooms->position[dim_x] +
                           d->rooms->size[dim_x] - 1));
  
  
  set_character_position_y(d->pc, range_y);
  set_character_position_x(d->pc, range_x);
}

void config_pc(dungeon_t *d)
{
  //Character* temp = (Character*) malloc(sizeof(Character));
  Character* temp_c = calloc_character();// calloc(1, get_character_size() ); //calloc_character();
  
  //printf("pc.c (41) temp_c: %lu\n", (long)temp_c); fflush( stdout );
  d->pc = temp_c;
  //printf("pc.c (44) p->c:%lu\n", (long)d->pc); fflush( stdout );
  //memset(d->pc, 0, sizeof (*d->pc));
  //printf("pc.c (44) p->c:%lu\n", (long)d->pc); fflush( stdout );
  
  set_symbol(d->pc, '@');

  place_pc(d);

  set_speed(d->pc, PC_SPEED);
  //if (!d->pc) { printf("NULL d->pc IN pc.c:54:config.pc\n"); fflush( stdout ); }
  set_alive(d->pc, 1);
  set_sequence_number(d->pc, 0);
  pc_t* temp_pc = calloc(1, sizeof (*get_pc(d)));
  set_pc(d, temp_pc);
  set_npc(d, NULL);

  int py = get_character_position_y(d->pc);
  int px = get_character_position_x(d->pc);
  d->character[py][px] = d->pc;
  
  dijkstra(d);
  //printf("pc.c (65)dijsktra p->c:%lu\n", (long)d->pc); fflush( stdout );
  dijkstra_tunnel(d);
  //printf("pc.c (67)dijsktra_tunnel p->c:%lu\n", (long)d->pc); fflush( stdout );
}

/* Not used anymore, but leaving it here because you could *
 * adapt it if you wanted to implement a bot player.       */
uint32_t pc_next_pos(dungeon_t *d, pair_t dir)
{
  dir[dim_y] = dir[dim_x] = 0;

  /* Tunnel to the nearest dungeon corner, then move around in hopes *
   * of killing a couple of monsters before we die ourself.          */

  if (in_corner(d, d->pc)) {
    /*
    dir[dim_x] = (mapxy(d->pc->position[dim_x] - 1,
                        d->pc->position[dim_y]) ==
                  ter_wall_immutable) ? 1 : -1;
    */
    dir[dim_y] = (mapxy(get_character_position_x(d->pc),
                        get_character_position_y(d->pc) - 1) ==
                  ter_wall_immutable) ? 1 : -1;
  } else {
    dir_nearest_wall(d, d->pc, dir);
  }

  return 0;
}
