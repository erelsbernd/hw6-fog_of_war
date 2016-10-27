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
    
    temp->symbol = 'Q';
    //printf("char symbol %c\n", temp->symbol);
    temp->position[dim_y] = -1;
    //printf("pair_t[dim_y] = %hhd\n", temp->position[dim_y]);
    temp->position[dim_x] = -1;
    //printf("pair_t[dim_x] = %hhd\n", temp->position[dim_x]);
    
    temp->speed = -1;
    //printf("speed = %d\n", temp->speed);
    temp->alive = -1;
    //printf("alive = %d\n", temp->alive);
    temp->sequence_number = -1;
    //printf("sequence_numver = %d\n", temp->sequence_number);
    temp->npc = NULL;
    //printf("NPC = %lu\n", (unsigned long)temp->npc);
    temp->pc = NULL;
    //printf("PC = %lu\n", (unsigned long)temp->pc);
    
    
    
    //printf("Calloc returns address#: %lu\n", (long)temp); fflush( stdout );
    
    
//    class Character { char symbol; pair_t position; int32_t speed;
//      uint32_t alive; uint32_t sequence_number; npc_t *npc; pc_t *pc;
    
    return temp;
    
//   sizeof(char) + sizeof(pair_t) + sizeof(int32_t) + sizeof(uint32_t) +
//                  sizeof(uint32_t) + sizeof(npc_t) + sizeof(pc_t) );
  }
  
  pair_t* get_pair_t(Character *c) {
    if (c) { return &c->position; }
    //printf("NULL C IN Character.cpp:34:get_pair_t\n"); fflush( stdout );
    return NULL;
  }
  
  int get_character_position_x(const Character *const c) {
    if (c) { return c->position[dim_x]; }
    //printf("NULL C IN Character.cpp:41:get_character_position_x\n"); fflush( stdout );
    return -1;
  }
  
  int get_character_position_y(const Character *const c) {
    if (c) { return c->position[dim_y]; }
    //printf("NULL C IN Character.cpp:46:get_character_position_y\n"); fflush( stdout );
    return -1;
  }
  
  int set_character_position_x(Character *c, int x) {
    if (c) {
      c->position[dim_x] = x;
      return c->position[dim_x];
    }
    //printf("NULL C IN Character.cpp:51:set_character_position_x\n"); fflush( stdout );
    return -1;
  }
  
  int set_character_position_y(Character *c, int y) {
    if (c) {
      c->position[dim_y] = y;
      return c->position[dim_y];
    }
    //printf("NULL C IN Character.cpp:60:set_character_position_y\n"); fflush( stdout );
    return -1;
  }
  
  npc_t* set_npc(Character *c, npc_t *npc) {
    if (c) {
      return c->npc = npc;
    }
    //printf("NULL C IN Character.cpp:69:set_npc\n"); fflush( stdout );
    return NULL;
  }
  
  npc_t* get_npc(Character *c) {
    if (c) { return c->npc; }
    //printf("NULL C IN Character.cpp:77:get_npc\n"); fflush( stdout );
    return NULL;
  }
  
  pc_t* set_pc(Character *c, pc_t *pc) {
    if (c) { return c->pc = pc; }
    //printf("NULL C IN Character.cpp:83:set_pc\n"); fflush( stdout );
    return NULL;
  }
  
  pc_t* get_pc(Character *c) {
    if (c) { return c->pc; }
    //printf("NULL C IN Character.cpp:89:get_pc\n"); fflush( stdout );
    return NULL;
  }
  
  int is_alive(Character *c) {
    if (c) { return c->alive; }
    //printf("NULL C IN Character.cpp:95:is_alive\n"); fflush( stdout );
    return 0;
  }
  
  int set_alive(Character *c, int alive){
    if (c) { return c->alive = alive; }
    //printf("NULL C IN Character.cpp:112:set_alive\n"); fflush( stdout );
    return 0;
  }
  
  char set_symbol(Character *c, char symbol) {
    if (c) { return c->symbol = symbol; return symbol; }
    //printf("NULL C IN Character.cpp:106:set_symbol\n"); fflush( stdout );
    return ' ';
  }
  
  char get_symbol(Character *c) {
    //printf("THE VALUE OF CHARACTER IN GET_SYMBOL IS :%lu", (long)c); fflush( stdout );
    if (c) { return c->symbol; }
    //printf("NULL C IN Character.cpp:106:set_symbol\n");  fflush( stdout );
    return ' ';
  }
  
  int32_t set_speed(Character *c, int32_t speed) {
    if (c) { return c->speed = speed; }
    //printf("NULL C IN Character.cpp:119:set_speed\n");  fflush( stdout );
    return 0;
  }
  
  int32_t get_speed(Character *c) {
    if (c) { return c->speed; }
    //printf("NULL C IN Character.cpp:127:get_speed\n");  fflush( stdout );
    return 0;
  }
  
  int32_t set_sequence_number(Character *c, int32_t num) {
    if (c) { return c->sequence_number = num; }
    //printf("NULL C IN Character.cpp:131:set_sequence_number\n");  fflush( stdout );
    return 0;
  }
  
  int32_t get_sequence_number(Character *c) {
    if (c) { return c->sequence_number; }
    //printf("NULL C IN Character.cpp:137:get_sequence_number\n");  fflush( stdout );
    return 0;
  }
  
  
  
#ifdef __cplusplus
}
#endif //__cplusplus


