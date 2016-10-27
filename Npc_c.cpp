#include <stdlib.h>

#include "utils.h"
#include "Npc_c.hpp"
#include "dungeon.h"
#include "character_t.h"
#include "move.h"
#include "path.h"
#include "event.h"


uint32_t has_characteristic(Npc* n, uint32_t bit) {
  return n->has_characteristic(bit);
}

uint32_t Npc::has_characteristic(uint32_t bit) {
  return this->characteristics & bit;
}

uint32_t add_characteristic(Npc* n, uint32_t bit) {
  return n->add_characteristic(bit);
}
uint32_t Npc::add_characteristic(uint32_t bit) {
  return this->characteristics = this->characteristics | bit;
}

uint32_t set_all_characteristics(Npc* n, uint32_t bit) {
  return n->set_all_characteristics(bit);
}
uint32_t Npc::set_all_characteristics(uint32_t bit) {
  return this->characteristics = bit;
}

uint32_t seen_pc(Npc* n) {
  return n->seen_pc();
}
uint32_t Npc::seen_pc() {
  return this->have_seen_pc;
}

uint32_t set_seen_pc(Npc* n, uint32_t seen) {
  return n->seen_pc();
}
uint32_t Npc::set_seen_pc(uint32_t seen) {
  return this->have_seen_pc;
}

uint32_t get_pc_last_known_position_x(Npc* n) {
  return n->get_pc_last_known_position_x();
}
uint32_t Npc::get_pc_last_known_position_x() {
  return this->pc_last_known_position[dim_x];
}

uint32_t get_pc_last_known_position_y(Npc* n) {
  return n->get_pc_last_known_position_y();
}
uint32_t Npc::get_pc_last_known_position_y() {
  return this->pc_last_known_position[dim_y];
}

uint32_t set_pc_last_known_position_x(Npc* n, uint32_t x) {
  return n->get_pc_last_known_position_x();
}
uint32_t Npc::set_pc_last_known_position_x(uint32_t x) {
  return this->pc_last_known_position[dim_x] = x;
}

uint32_t set_pc_last_known_position_y(Npc* n, uint32_t y) {
  return n->get_pc_last_known_position_y();
}
uint32_t Npc::set_pc_last_known_position_y(uint32_t y) {
  return this->pc_last_known_position[dim_y] = y;
}
