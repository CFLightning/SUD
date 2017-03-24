#include "string"
#include "item.h"
#include "npc.h"

using namespace std;

Npc::Npc(string name, int baseHp, int baseDmg, int lvl, Item drop):Character(name, baseHp, baseDmg, lvl)
{
	this->hp = this->baseHp + lvl;
	this->maxHp = this->baseHp + lvl;
	this->dmg = this->baseDmg + lvl;
	this->drop = drop;
}

Npc::Npc():Character("No name", 1, 0, 0)
{
	this->maxHp = this->baseHp;
	this->dmg = this->baseDmg;
	this->hp = this->maxHp;
}

Item Npc::dropItem()
{
	return this->drop;	
}

void Npc::show()
{
	cout << "\nStatystyki\n"
		 << this->name << "\n" 
		 << this->hp << "/" << this->baseHp+this->lvl << "\tHP\n"
		 << this->dmg << "\tdph\n"
		 << this->lvl + 1 << "\tpoziom\n";
}

// Npc("antos", 10, 100, _items[10]);
