#ifndef _item_h_included
#define _item_h_included

#include "iostream"
#include "string"

using namespace std;

class Item
{
	private:
		string name;
		int price;
		int dmg;
		int hp;
		int slot;		// 0 - head, 1 - chest, 2 - weapon, 3 - none
	
	public:
		friend ostream& operator<<(ostream&, const Item&);
		int getPrice();
		bool isHelmet();
		bool isArmor();
		bool isWeapon();
		bool isNotUsable();
		
		Item(string, int, int, int, int);
};

#endif
