//
//  Character.hpp
//  hw6-fog_of_war
//
//  Created by Erin Elsbernd on 10/24/16.
//  Copyright © 2016 Erin Elsbernd. All rights reserved.
//

#ifndef Character_h
#define Character_h

#include <stdio.h>

#include "npc.h"
#include "pc.h"

class Character {
  char symbol;
  pair_t position;
  int32_t speed;
  uint32_t alive;
  uint32_t sequence_number;
  npc_t *npc;
  pc_t *pc;
};


#endif /* Character_hpp */
