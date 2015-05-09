#ifndef _player_h_included
#define _player_h_included

#include "character.h"
#include "vector"

class Player : public Character
{
	private:
	 int gold;
	 vector<Item> eq;
	 vector<Item> inventory;
	public:
	 void show();
	 void showEq();
	 int getGold();
	 void addGold(int);
	 void spendGold(int);
	 void showInventory();
	 Player();
};
