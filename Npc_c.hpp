#ifndef NPC_HPP
# define NPC_HPP

# include <stdint.h>

# include "dims.h"

# define NPC_SMART         0x00000001
# define NPC_TELEPATH      0x00000002
# define NPC_TUNNEL        0x00000004
# define NPC_ERRATIC       0x00000008


typedef struct dungeon dungeon_t;
typedef uint32_t npc_characteristics_t;

#ifndef __cplusplus
//define has_characteristic(character, bit)              \
//((character)->npc->characteristics & NPC##bit)

typedef void Character;


typedef struct npc {
  npc_characteristics_t characteristics;
  uint32_t have_seen_pc;
  pair_t pc_last_known_position;
  
} npc_t;


#else //__cplusplus
#include "Character.hpp"

class Npc: public Character {
private:
  npc_characteristics_t characteristics;
  uint32_t have_seen_pc;
  pair_t pc_last_known_position;
  
public:
  uint32_t has_characteristic(uint32_t bit);
  uint32_t add_characteristic(uint32_t bit);
  uint32_t set_all_characteristics(uint32_t bit);
  
  uint32_t seen_pc();
  uint32_t set_seen_pc(uint32_t seen);
  
  uint32_t get_pc_last_known_position_x();
  uint32_t get_pc_last_known_position_y();
  uint32_t set_pc_last_known_position_x(uint32_t x);
  uint32_t set_pc_last_known_position_y(uint32_t y);
};

#endif //__cplusplus


#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
  
  uint32_t has_characteristic(Npc* n, uint32_t bit);
  uint32_t add_characteristic(Npc* n, uint32_t bit);
  uint32_t set_all_characteristics(Npc* n, uint32_t bit);
  
  uint32_t seen_pc(Npc* n);
  uint32_t set_seen_pc(Npc* n, uint32_t seen);
  
  uint32_t get_pc_last_known_position_x(Npc* n);
  uint32_t get_pc_last_known_position_y(Npc* n);
  uint32_t set_pc_last_known_position_x(Npc* n, uint32_t x);
  uint32_t set_pc_last_known_position_y(Npc* n, uint32_t y);
  
///void npc_delete(npc_t *n);
  
  
#ifdef __cplusplus
}
#endif //__cplusplus



#endif
