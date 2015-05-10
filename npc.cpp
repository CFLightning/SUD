#include "string"
#include "item.h"
#include "npc.h"

using namespace std;

Npc::Npc(string name, int hp, int dmg, Item drop, int lvl)
{
	this->name=name;
	this->baseHp=hp;
	this->dmg=dmg;
	this->drop=drop;
	this->lvl=lvl;
}

void Npc::dropItem(Player player)
{
	player.takeItem(this->drop);	
}

// Npc("antos", 10, 100, _items[10]);
