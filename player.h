#ifndef _player_h_included
#define _player_h_included

#include "vector"
#include "string"
#include "character.h"
#include "item.h"

using namespace std;

class Player: public Character
{
	private:
	 int gold;
	 vector<int> eq;
	 vector<Item> inventory;
	 
	public:
	 void show();
	 void showEq();
	 int getGold();
	 void addGold(int);
	 void spendGold(int);
	 void takeItem(Item);
	 void giveItem(int);
	 bool equipItem(int);
	 bool dequipItem(int);
	 void showInventory();
	 Item getItemFromInventory(int);
	 void update();
	 void levelUp();
	 void levelDown();
	 void interactionBonus(int, int);
	 Player(string, int, int, int, int);
	 Player();
};

#endif
