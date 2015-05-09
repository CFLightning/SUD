#include "npc.h"

using namespace std;

Npc::Npc(string name, int hp, int dmg, Item drop)
{
	this->name=name;
	this->baseHp=hp;
	this->dmg=dmg;
	this->drop=drop;
}

// Npc("antos", 10, 100, _items[10]);
