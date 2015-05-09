#include "player.h"
#include "vector"

using namespace std;

Player::Player(string name, int baseHp, int baseDmg, int gold)
{
	this->baseHp = baseHp;
	this->baseDmg = baseDmg;
	
	this->maxHp = this->baseHp + this->eq[0] + this->eq[1] + this->eq[2] + this->lvl;
	this->dmg = this->baseDmg + this->eq[0] + this->eq[1] + this->eq[2] + this->lvl;
	
	this->name=name;
	this->gold=gold;
	this->hp=this->maxHp;
	this->lvl=1;
}

void Player::update()
{
	this->maxHp = this->baseHp + this->eq[0] + this->eq[1] + this->eq[2] + this->lvl;
	this->dmg = this->baseDmg + this->eq[0] + this->eq[1] + this->eq[2] + this->lvl;
}
