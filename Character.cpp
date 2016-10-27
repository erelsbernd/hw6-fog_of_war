# include <iostream>
# include <string>
# include <stdio.h>
# include <stdlib.h>

#include "Character.hpp"


// C++ class implementation here
#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
  
  
  int get_character_size() {
    return sizeof(Character);
  }
  
  Character* calloc_character() {
    //printf("size of Character = %lu\n", sizeof(Character));
    Character* temp = (Character*) calloc(1, sizeof(Character));
    //printf("size of calloc C = %lu\n", sizeof(*temp));
    
    temp->set_symbol('Q');
    //printf("char symbol %c\n", temp->symbol);
    temp->set_character_position_y(-1);
    //printf("pair_t[dim_y] = %hhd\n", temp->position[dim_y]);
    temp->set_character_position_x(-1);
    //printf("pair_t[dim_x] = %hhd\n", temp->position[dim_x]);
    
    temp->set_speed(-1);
    //printf("speed = %d\n", temp->speed);
    temp->set_alive(-1);
    //printf("alive = %d\n", temp->alive);
    temp->set_sequence_number(-1);
    //printf("sequence_numver = %d\n", temp->sequence_number);
    temp->set_npc(NULL);
    //printf("NPC = %lu\n", (unsigned long)temp->npc);
    temp->set_pc(NULL);
    //printf("PC = %lu\n", (unsigned long)temp->pc);
    
    
    
    //printf("Calloc returns address#: %lu\n", (long)temp); fflush( stdout );
    
    
    return temp;
    
//    class Character { char symbol; pair_t position; int32_t speed;
//      uint32_t alive; uint32_t sequence_number; npc_t *npc; pc_t *pc;
//   sizeof(char) + sizeof(pair_t) + sizeof(int32_t) + sizeof(uint32_t) +
//                  sizeof(uint32_t) + sizeof(npc_t) + sizeof(pc_t) );
  }
  
  pair_t* get_pair_t(Character *c) {
    if (c) { return c->get_pair_t(); }
    //printf("NULL C IN Character.cpp:34:get_pair_t\n"); fflush( stdout );
    return NULL;
  }
  pair_t* Character::get_pair_t() { return &position; }
  
  int get_character_position_x(const Character *const c) {
    if (c) { return c->get_character_position_x(); }
    //printf("NULL C IN Character.cpp:41:get_character_position_x\n"); fflush( stdout );
    return -1;
  }
  int Character::get_character_position_x() const { return position[dim_x]; }
  
  int get_character_position_y(const Character *const c) {
    if (c) { return c->get_character_position_y(); }
    //printf("NULL C IN Character.cpp:41:get_character_position_x\n"); fflush( stdout );
    return -1;
  }
  int Character::get_character_position_y() const { return position[dim_y]; }
  
  
  int set_character_position_x(Character *c, int x) {
    if (c) {
      return c->set_character_position_y(x);
    }
    //printf("NULL C IN Character.cpp:51:set_character_position_x\n"); fflush( stdout );
    return -1;
  }
  int Character::set_character_position_x(int x) {
    return position[dim_x] = x;
  }
  
  int set_character_position_y(Character *c, int y) {
    if (c) {
      return c->set_character_position_y(y);
    }
    //printf("NULL C IN Character.cpp:51:set_character_position_x\n"); fflush( stdout );
    return -1;
  }
  int Character::set_character_position_y(int y) {
    return position[dim_y] = y;
  }
  
  npc_t* set_npc(Character *c, npc_t *npc) {
    if (c) {
      return c->set_npc(npc);
    }
    //printf("NULL C IN Character.cpp:69:set_npc\n"); fflush( stdout );
    return NULL;
  }
  npc_t* Character::set_npc(npc_t *npc) {
    return this->npc = npc;
  }
  
  npc_t* get_npc(Character *c) {
    if (c) { return c->get_npc(); }
    //printf("NULL C IN Character.cpp:77:get_npc\n"); fflush( stdout );
    return NULL;
  }
  npc_t* Character::get_npc() {
    return npc;
  }
  
  pc_t* set_pc(Character *c, pc_t *pc) {
    if (c) { return c->set_pc(pc); }
    //printf("NULL C IN Character.cpp:83:set_pc\n"); fflush( stdout );
    return NULL;
  }
  pc_t* Character::set_pc(pc_t *pc) {
    return this->pc = pc;
  }
  
  pc_t* get_pc(Character *c) {
    if (c) { return c->get_pc(); }
    //printf("NULL C IN Character.cpp:89:get_pc\n"); fflush( stdout );
    return NULL;
  }
  pc_t* Character::get_pc() {
    return pc;
  }
  
  int is_alive(Character *c) {
    if (c) { return c->is_alive(); }
    //printf("NULL C IN Character.cpp:95:is_alive\n"); fflush( stdout );
    return 0;
  }
  int Character::is_alive() {
    return alive;
  }
  
  int set_alive(Character *c, int alive){
    if (c) { return c->set_alive(alive); }
    //printf("NULL C IN Character.cpp:112:set_alive\n"); fflush( stdout );
    return 0;
  }
  int Character::set_alive(int alive){
    return this->alive = alive;
  }
  
  char set_symbol(Character *c, char symbol) {
    if (c) { return c->set_symbol(symbol); }
    //printf("NULL C IN Character.cpp:106:set_symbol\n"); fflush( stdout );
    return ' ';
  }
  char Character::set_symbol(char symbol) {
    return this->symbol = symbol;
  }
  
  char get_symbol(Character *c) {
    //printf("THE VALUE OF CHARACTER IN GET_SYMBOL IS :%lu", (long)c); fflush( stdout );
    if (c) { return c->get_symbol(); }
    //printf("NULL C IN Character.cpp:106:set_symbol\n");  fflush( stdout );
    return ' ';
  }
  char Character::get_symbol() {
    return symbol;
  }
  
  int32_t set_speed(Character *c, int32_t speed) {
    if (c) { return c->set_speed(speed); }
    //printf("NULL C IN Character.cpp:119:set_speed\n");  fflush( stdout );
    return 0;
  }
  int32_t Character::set_speed(int32_t speed) {
    return this->speed = speed;
  }
  
  int32_t get_speed(Character *c) {
    if (c) { return c->get_speed(); }
    //printf("NULL C IN Character.cpp:127:get_speed\n");  fflush( stdout );
    return 0;
  }
  int32_t Character::get_speed() {
    return speed;
  }
  
  int32_t set_sequence_number(Character *c, int32_t num) {
    if (c) { return c->set_sequence_number(num); }
    //printf("NULL C IN Character.cpp:131:set_sequence_number\n");  fflush( stdout );
    return 0;
  }
  int32_t Character::set_sequence_number(int32_t num) {
    return this->sequence_number = num;
  }
  
  int32_t get_sequence_number(Character *c) {
    if (c) { return c->get_sequence_number(); }
    //printf("NULL C IN Character.cpp:137:get_sequence_number\n");  fflush( stdout );
    return 0;
  }
  int32_t Character::get_sequence_number() {
    return this->sequence_number;
  }
  
  
  
#ifdef __cplusplus
}
#endif //__cplusplus


