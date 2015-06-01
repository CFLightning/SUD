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
		Shop(string, Player&, vector<Item>);
		bool sell(int, Player&);
		bool buy(int, Player&);
		void showStore();
		bool isInteraction() const;
		bool isBattle() const;
		bool isZero() const;
		bool isShop() const;
		//virtual int happen(Player&);
		
		int result();
};

#endif
