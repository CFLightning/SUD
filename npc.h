#ifndef _npc_h_included
#define _npc_h_included
 
#include "string"
#include "character.h"
#include "player.h"
#include "item.h"

class Npc: public Character
{
	private:
	 Item drop;
	public:
	 void dropItem(Player);
	 Npc(string, int, int, int, Item);
	 Npc();
	 void show();
};

#endif
