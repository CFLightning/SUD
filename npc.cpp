#include "string"
#include "item.h"
#include "npc.h"

using namespace std;

Npc::Npc(string name, int hp, int dmg, int lvl, Item drop):Character(name, hp, dmg, lvl)
{
	this->hp = this->baseHp + lvl;
	this->maxHp = this->baseHp + lvl;
	this->dmg = this->baseDmg + lvl;
	this->drop = drop;
}

void Npc::dropItem(Player player)
{
	player.takeItem(this->drop);	
}

void Npc::show()
{
	cout << "\nStatystyki\n"
		 << this->name << "\n" 
		 << this->hp << "/" << this->baseHp+this->lvl << "\tHP\n"
		 << this->dmg << "\tdph\n"
		 << this->lvl + 1 << "\tpoziom\n"
		 << this->description << "\n";
}

// Npc("antos", 10, 100, _items[10]);
