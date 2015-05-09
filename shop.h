#ifndef _shop_h_included
#define _shop_h_included

#include "vector"
#include "event.h"

class Shop: public Event
{
	private:
		vector<item> store;
	
	public:
		bool sell(Item, Player);
		bool buy(Item, Player);
		void showStore();
		bool isShop();
		
		int result();
};

#endif
