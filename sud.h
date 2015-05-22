#ifndef _sud_h_defined
#define _sud_h_defined

#include "player.h"
#include "character.h"
#include "event.h"
#include "npc.h"
#include "item.h"
#include "shop.h"

#include "vector"

#define _itemsPath "data/items.dat"

class Sud
{
	private:
		vector<Item> items;
	
	public:
		bool init();
		
		Item getItem(int);
		int howMuchItems();
};

#endif
