#ifndef _shop_h_included
#define _shop_h_included

#include "vector"
#include "event.h"
#include "item.h"
#include "player.h"

class Shop: public Event
{
	private:
		vector<Item> store;
	
	public:
		bool sell(Item, Player);
		bool buy(Item, Player);
		void showStore();
		bool isShop();
		
		int result();
};

#endif
