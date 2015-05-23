#include "string"
#include "vector"
#include "iostream"

#include "character.h"

using namespace std;

void Character::takeDMG(Character enemy)
{
	this->hp -= enemy.getDMG();
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
