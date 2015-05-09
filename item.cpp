#include "item.h"

using namespace std;

Item::Item(string name, int price, int dmg, int hp, int slot)
{
	this->name = name;
	this->price = price;
	this->hp = hp;
	this->dmg = dmg;
	this->slot = slot;
}

bool Item::isHelmet()
{
	if(this->slot == 0)
		return true;
	else
		return false;
}

bool Item::isArmor()
{
	if(this->slot == 1)
		return true;
	else
		return false;
}

bool Item::isWeapon()
{
	if(this->slot == 2)
		return true;
	else
		return false;
}

bool Item::isNotUsable()
{
	if(this->slot == 3)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& ostr, const Item& item)
{
	ostr << item.name;
	
	return ostr;
}
