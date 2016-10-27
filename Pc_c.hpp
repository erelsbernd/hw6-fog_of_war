#ifndef PC_C_HPP
#define PC_C_HPP

# include <stdint.h>

# include "dims.h"

typedef struct dungeon dungeon_t;



#ifndef __cplusplus

typedef struct pc_s {
} pc_t;

typedef void Character;


#else //__cplusplus
#include "Character.hpp"

class Pc_c: public Character {
private:
  uint32_t stairs_climbed;
  uint32_t stairs_descended;
  uint32_t dungeon_levels_cleared;
  
public:
  uint32_t get_stairs_climbed();
  uint32_t set_stairs_climbed(uint32_t num);
  
  uint32_t get_stairs_descended();
  uint32_t set_stairs_descended(uint32_t num);
  
  uint32_t get_dungeon_levels_cleared();
  uint32_t set_dungeon_levels_cleared(uint32_t num);
};

#endif //__cplusplus


#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
  
  uint32_t get_stairs_climbed(Pc_c *p);
  uint32_t set_stairs_climbed(Pc_c *p, uint32_t num);
  
  uint32_t get_stairs_descended(Pc_c *p);
  uint32_t set_stairs_descended(Pc_c *p, uint32_t num);
  
  uint32_t get_dungeon_levels_cleared(Pc_c *p);
  uint32_t set_dungeon_levels_cleared(Pc_c *p, uint32_t num);
  
  
#ifdef __cplusplus
}
#endif //__cplusplus

#endif
