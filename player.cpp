#include "vector"
#include "iostream"
#include "item.h"
#include "player.h"

using namespace std;

Player::Player(string name, int baseHp, int baseDmg, int lvl, int gold):Character(name, baseHp, baseDmg, lvl)
{
	for(int i = 0; i < 3; i++)
		this->eq.push_back(Item());
		
	this->maxHp = this->baseHp + this->eq[0].getHpBonus() + this->eq[1].getHpBonus() + this->eq[2].getHpBonus() + this->lvl;
	this->dmg = this->baseDmg + this->eq[0].getDmgBonus() + this->eq[1].getDmgBonus() + this->eq[2].getDmgBonus() + this->lvl;
	
	this->gold = gold;
	this->hp = this->maxHp;
}

void Player::update()
{
	this->maxHp = this->baseHp + this->eq[0].getHpBonus() + this->eq[1].getHpBonus() + this->eq[2].getHpBonus() + this->lvl;
	this->dmg = this->baseDmg + this->eq[0].getDmgBonus() + this->eq[1].getDmgBonus() + this->eq[2].getDmgBonus() + this->lvl;
}

int Player::getGold()
{
	return this->gold;
}

void Player::showEq()
{
	for(int i = 0; i < this->eq.size(); i++)
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
	this->inventory.erase(inventory.begin() + item);
}

void Player::show()
{
	cout << "\nStatystyki\n"
		 << this->name << "\n" 
		 << this->hp << "/" << this->baseHp+this->lvl << "\tHP\n"
		 << this->dmg << "\tdph\n"
		 << this->lvl << "\tpoziom\n"
		 << this->gold << "\tmunies\n"
		 << this->description << "\n";
}
