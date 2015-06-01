#include "string"
#include "vector"
#include "iostream"

#include "character.h"

using namespace std;

void Character::takeDMG(int dmg)
{
	this->hp -= dmg;
}

int Character::getDMG()
{
	return dmg;
}

Character::Character(string name, int baseHp, int baseDmg, int lvl)
{
	this->name = name;
	this->baseHp = baseHp;
	this->baseDmg = baseDmg;
	this->lvl = lvl;
}

string Character::getName()
{
	return this->name;
}

int Character::getMaxHp()
{
	return this->maxHp;
}

int Character::getHp()
{
	return this->hp;
}

int Character::getLvl()
{
	return lvl;
}
