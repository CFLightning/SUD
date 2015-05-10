#include "string"
#include "iostream"
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

Item::Item()
{
	this->name = "ExampleItem";
	this->price = 0;
	this->hp = 0;
	this->dmg = 0;
	this->slot = 3;
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

int Item::getPrice()
{
	return this->price;
}

ostream& operator<<(ostream& ostr, const Item& item)
{
	ostr << item.name;
	
	return ostr;
}

int Item::getHpBonus()
{
	return this->hp;
}

int Item::getDmgBonus()
{
	return this->dmg;
}
