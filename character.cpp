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

void Character::show()
{
	cout << "\nStatystyki\n"
		 << this->name << "\n" 
		 << this->hp << "/" << this->baseHp+this->lvl << "HP\n"
		 << this->dmg << "dph\n"
		 << this->lvl << "poziom\n"
		 << this->description << "\n";
}
