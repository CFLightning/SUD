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

Player::Player():Character("No name", 1, 0, 0)
{
	this->inventory.push_back(Item());
	
	for(int i = 0; i < 3; i++)
		this->eq.push_back(0);
		
	this->maxHp = this->baseHp;
	this->dmg = this->baseDmg;
	
	this->gold = 0;
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
	if(received.getName() == "No item")
		cout << "Did not received any item\n";
	else
	{
		this->inventory.push_back(received);
		cout << "Received item: " << this->inventory[this->inventory.size() - 1] << "\n";
	}
}

void Player::giveItem(int item)
{
	this->inventory.erase(inventory.begin() + item);
}

void Player::show()
{
	cout << "\nStatystyki\n"
		 << this->name << "\n" 
		 << this->hp << "/" << this->maxHp << "\tHP\n"
		 << this->dmg << "\tdph\n"
		 << this->lvl + 1 << "\tpoziom\n"
		 << this->gold << "\tmunies\n";
}

bool Player::equipItem(int item)
{
	if(item >= this->inventory.size())
		return false;
	else if(this->inventory[item].isHelmet())
	{
		this->eq[0] = item;
		this->update();
		this->hp=this->maxHp;
		return true;
	}
	else if(this->inventory[item].isArmor())
	{
		this->eq[1] = item;
		this->update();
		this->hp=this->maxHp;
		return true;
	}
	else if(this->inventory[item].isWeapon())
	{
		this->eq[2] = item;
		this->update();
		this->hp=this->maxHp;
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

Item Player::getItemFromInventory(int item)
{
	return this->inventory[item];
}

void Player::levelUp()
{
	this->lvl++;
	this->update();
}

void Player::levelDown()
{
	this->lvl--;
	this->update();
}

void Player::interactionBonus(int bonusHP, int bonusDMG)
{
	this->baseHp += bonusHP;
	this->baseDmg += bonusDMG;
	this->update();
}
