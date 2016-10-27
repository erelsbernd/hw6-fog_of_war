#ifndef NPC_H
# define NPC_H

# include <stdint.h>

# include "dims.h"
//# include "Character.hpp"

# define NPC_SMART         0x00000001
# define NPC_TELEPATH      0x00000002
# define NPC_TUNNEL        0x00000004
# define NPC_ERRATIC       0x00000008

#ifndef __cplusplus
typedef void Character;
#else //__cplusplus
class Character;
#endif //__cplusplus

typedef struct dungeon dungeon_t;
typedef uint32_t npc_characteristics_t;

typedef struct npc {
  npc_characteristics_t characteristics;
  uint32_t have_seen_pc;
  pair_t pc_last_known_position;

} npc_t;

void gen_monsters(dungeon_t *d);
void npc_delete(npc_t *n);
void npc_next_pos(dungeon_t *d, Character *c, pair_t next);
uint32_t dungeon_has_npcs(dungeon_t *d);

#endif
