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
	this->lvl=1;
}

void Player::show()
{
	cout << "\nStatystyki\n"
		 << this->name << "\n" 
		 << this->hp << "/" << this->baseHp+this->lvl << "HP\n"
		 << this->dmg << "dph\n"
		 <<
}
zeglen
20ad
20/40hp
gruby kutas 
20lvl
jest bogaty w 40 zydogaleonow


