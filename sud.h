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
#define _eventsPath "data/events.dat"
#define _npcsPath "data/npcs.dat"

#define _map_size_x 4
#define _map_size_y 4

class Sud
{
	private:
		Player pl;
		Event currentEvent;
		bool traveled;
		bool debug_mode;
		
		int currentPosX;
		int currentPosY;
		
		vector<Item> items;
		vector<Event> events;
		vector<Npc> enemies;
		vector<vector<Event> > map;
	
	public:
		bool init();
		bool start();
		
		Item getItem(int);
		int howMuchItems();
		int findItemByName(string);
};

#endif
