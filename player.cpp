#include "vector"
#include "iostream"
#include "item.h"
#include "player.h"

using namespace std;

Player::Player(string name, int baseHp, int baseDmg, int lvl, int gold):Character(name, baseHp, baseDmg, lvl)
{
	this->inventory.push_back(Item());
	
	for(int i = 0; i < 3; i++)
		this->eq.push_back(0);
		
	this->maxHp = this->baseHp + this->inventory[eq[0]].getHpBonus() + this->inventory[eq[1]].getHpBonus() + this->inventory[eq[2]].getHpBonus() + this->lvl;
	this->dmg = this->baseDmg + this->inventory[eq[0]].getDmgBonus() + this->inventory[eq[1]].getDmgBonus() + this->inventory[eq[2]].getDmgBonus() + this->lvl;
	
	this->gold = gold;
	this->hp = this->maxHp;
}

void Player::update()
{
	this->maxHp = this->baseHp + this->inventory[eq[0]].getHpBonus() + this->inventory[eq[1]].getHpBonus() + this->inventory[eq[2]].getHpBonus() + this->lvl;
	this->dmg = this->baseDmg + this->inventory[eq[0]].getDmgBonus() + this->inventory[eq[1]].getDmgBonus() + this->inventory[eq[2]].getDmgBonus() + this->lvl;
}

int Player::getGold()
{
	return this->gold;
}

void Player::showEq()
{
	cout << "Head\t" << this->inventory[eq[0]] << "\n"
		 << "Armor\t" << this->inventory[eq[1]] << "\n"
		 << "Weapon\t" << this->inventory[eq[2]] << "\n";
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
	cout << "Received item: " << this->inventory[this->inventory.size() - 1] << "\n";
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

bool Player::equipItem(int item)
{
	if(this->inventory[item].isHelmet())
	{
		this->eq[0] = item;
		this->update();
		return true;
	}
	if(this->inventory[item].isArmor())
	{
		this->eq[1] = item;
		this->update();
		return true;
	}
	if(this->inventory[item].isWeapon())
	{
		this->eq[2] = item;
		this->update();
		return true;
	}
	else
		return false;
}

bool Player::dequipItem(int slot)
{
	this->eq[slot] = 0;
}

void Player::showInventory()
{
	for(int i = 1; i < this->inventory.size(); i++)
		cout << i << "\t" << this->inventory[i] << "\n";
}
