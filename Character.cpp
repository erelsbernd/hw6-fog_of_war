# include <iostream>
# include <string>

#include "Character.hpp"


// C++ class implementation here
#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
  
  
  int get_character_size() {
    return sizeof(Character);
  }
  
  Character* malloc_character() {
    Character* temp = (Character*) malloc(sizeof(Character));
    printf("Malloc returns address#: %lu\n", (long)temp);
    fflush( stdout );
    return temp;
//                  sizeof(char) +
//                  sizeof(pair_t) +
//                  sizeof(int32_t) +
//                  sizeof(uint32_t) +
//                  sizeof(uint32_t) +
//                  sizeof(npc_t) +
//                  sizeof(pc_t)
//                  );
  }
  
  pair_t* get_pair_t(Character *c) {
    return &c->position;
  }
  
  int get_character_position_x(const Character *const c) {
    return c->position[dim_x];
  }
  
  int get_character_position_y(const Character *const c) {
    return c->position[dim_y];
  }
  
  int set_character_position_x(Character *c, int x) {
    c->position[dim_x] = x;
    return c->position[dim_x];
  }
  
  int set_character_position_y(Character *c, int y) {
    c->position[dim_y] = y;
    return c->position[dim_y];
  }
  
  npc_t* set_npc(Character *c, npc_t *npc) {
    return c->npc = npc;
  }
  
  npc_t* get_npc(Character *c) {
    return c->npc;
  }
  
  pc_t* set_pc(Character *c, pc_t *pc) {
    return c->pc = pc;
  }
  
  pc_t* get_pc(Character *c) {
    return c->pc;
  }
  
  int is_alive(Character *c) {
    return c->alive;
  }
  
  void set_alive(Character *c, int alive){
    c->alive = alive;
  }
  
  char set_symbol(Character *c, char symbol) {
    return c->symbol = symbol;
  }
  
  char get_symbol(Character *c) {
    printf("THE VALUE OF CHARACTER IN GET_SYMBOL IS :%lu", (long)c); fflush( stdout );
    return c->symbol;
  }
  
  int32_t set_speed(Character *c, int32_t speed) {
    return c->speed = speed;
  }
  
  int32_t get_speed(Character *c) {
    return c->speed;
  }
  
  int32_t set_sequence_number(Character *c, int32_t num) {
    return c->sequence_number = num;
  }
  
  int32_t get_sequence_number(Character *c) {
    return c->sequence_number;
  }
  
  
  
#ifdef __cplusplus
}
#endif //__cplusplus


