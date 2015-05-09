#include "player.h"
#include "vector"

using namespace std;

Player::Player(string name, int baseHp, int dmg, int gold)
{
	this->baseHp=baseHp;
	this->dmg=dmg;
	this->name=name;
	this->gold=gold;
	this->hp=baseHP;
}


