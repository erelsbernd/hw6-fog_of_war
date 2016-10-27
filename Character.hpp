//
//  Character.hpp
//  hw6-fog_of_war
//
//  Created by Erin Elsbernd on 10/24/16.
//  Copyright © 2016 Erin Elsbernd. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>

#include "npc.h"
#include "pc.h"

#ifdef __cplusplus


class Character {
private:
  char symbol;
  pair_t position;
  int32_t speed;
  uint32_t alive;
  uint32_t sequence_number;
  npc_t *npc;
  pc_t *pc;
  
public:
  pair_t* get_pair_t();
  int get_character_position_x() const;
  int get_character_position_y() const;
  int set_character_position_x(int x);
  int set_character_position_y(int y);
  int set_alive(int alive);
  int is_alive();
  char set_symbol(char symbol);
  char get_symbol();
  int32_t set_speed(int32_t speed);
  int32_t get_speed();
  int32_t set_sequence_number(int32_t num);
  int32_t get_sequence_number();
  npc_t* set_npc(npc_t *npc);
  npc_t* get_npc();
  pc_t* set_pc(pc_t *pc);
  pc_t* get_pc();
  
  //pair_t getPosition();
};

#else

typedef void Character;

#endif //__cplusplus


#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
  
  
  // C code here
  //something to get and set pc->position[dim_x] and [dim_y]
  
  int get_character_size();
  Character* calloc_character();
  pair_t* get_pair_t(Character *c);
  int get_character_position_x(const Character *const c);
  int get_character_position_y(const Character *const c);
  int set_character_position_x(Character *c, int x);
  int set_character_position_y(Character *c, int y);
  int set_alive(Character *c, int alive);
  int is_alive(Character *c);
  char set_symbol(Character *c, char symbol);
  char get_symbol(Character *c);
  int32_t set_speed(Character *c, int32_t speed);
  int32_t get_speed(Character *c);
  int32_t set_sequence_number(Character *c, int32_t num);
  int32_t get_sequence_number(Character *c);
  npc_t* set_npc(Character *c, npc_t *npc);
  npc_t* get_npc(Character *c);
  pc_t* set_pc(Character *c, pc_t *pc);
  pc_t* get_pc(Character *c);
  
  
  
  
#ifdef __cplusplus
}
#endif //__cplusplus



#endif /* Character_hpp */
