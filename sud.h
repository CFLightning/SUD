#ifndef _sud_h_defined
#define _sud_h_defined

#include "player.h"
#include "character.h"
#include "event.h"
#include "npc.h"
#include "item.h"
#include "shop.h"
#include "interaction.h"

#include "vector"

#define _itemsPath "data/items.dat"
#define _npcsPath "data/npcs.dat"
#define _interactionsPath "data/interactions.dat"

#define _map_size_x 15
#define _map_size_y 15

class Sud
{
	private:
		Player pl;
		bool traveled;
		bool debug_mode;
		
		int currentPosX;
		int currentPosY;
		
		vector<Item> items;
		vector<Interaction> events;
		vector<Npc> enemies;
		vector<vector<int> > map;
	
	public:
		bool init();
		bool start();
		
		Item getItem(int);
		int howMuchItems();
		int findItemByName(string);
};

#endif
