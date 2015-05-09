#include "player.h"
#include "vector"
#include "iostream"

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

int Player::getGold()
{
	return this->gold;
}

void Player::showEq()
{
	for(int i = 0; i<this->eq.size(); i++)
		cout << eq[i] << "\n";
}

void Player::addGold(int income)
{
	this->gold+=income;
}

void Player::spendGold(int payment)
{
	this->gold-=payment;
}

void Player::takeItem(Item received)
{
	this->inventory.push_back(received);
}

void Player::giveItem(int item)
{
	this->inventory.erase(item);
}



