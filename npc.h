#ifndef _npc_h_included
#define _npc_h_included
 
#include "character.h"

class Npc : public Character
{
	private:
	 Item drop
	public:
	 void dropItem(player);
	 Npc(string, int, int, Item);
};

#endif
