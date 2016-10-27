#include <stdlib.h>

#include "string.h"

#include "dungeon.h"
#include "Pc_c.hpp"
#include "utils.h"
#include "move.h"
#include "path.h"

uint32_t get_stairs_climbed(Pc_c *p) {
  return p->get_stairs_climbed();
}
uint32_t Pc_c::get_stairs_climbed() {
  return stairs_climbed;
}

uint32_t set_stairs_climbed(Pc_c *p, uint32_t num) {
  return p->set_stairs_climbed(num);
}
uint32_t Pc_c::set_stairs_climbed(uint32_t num) {
  return stairs_climbed = num;
}

uint32_t get_stairs_descended(Pc_c *p) {
  return p->get_stairs_descended();
}
uint32_t Pc_c::get_stairs_descended() {
  return stairs_descended;
}

uint32_t set_stairs_descended(Pc_c *p, uint32_t num) {
  return p->get_stairs_descended();
}
uint32_t Pc_c::set_stairs_descended(uint32_t num) {
  return stairs_descended = num;
}

uint32_t get_dungeon_levels_cleared(Pc_c *p) {
  return p->get_dungeon_levels_cleared();
}
uint32_t Pc_c::get_dungeon_levels_cleared() {
  return dungeon_levels_cleared;
}

uint32_t set_dungeon_levels_cleared(Pc_c *p, uint32_t num) {
  return p->set_dungeon_levels_cleared(num);
}
uint32_t Pc_c::set_dungeon_levels_cleared(uint32_t num) {
  return dungeon_levels_cleared = num;
}
