#include "iostream"
#include "shop.h"
#include "item.h"
#include "player.h"

using namespace std;

bool Shop::buy(int item, Player &player)
{
	if(player.getGold() < this->store[item].getPrice())
	{	
		cout << "Not enough monies\n";
		
		return false;
	}
	else
	{
		player.spendGold(this->store[item].getPrice());
		cout << "\nBought item: " << this->store[item] << "\n";
		player.takeItem(this->store[item]);
		
		return true;
	}
	
	return false;
}

bool Shop::sell(int item, Player &player)
{
	cout << "Sold item: " << player.getItemFromInventory(item) << "\nNo returns\n";
	
	player.addGold(player.getItemFromInventory(item).getPrice());
	player.giveItem(item);
	
	return true;
}

void Shop::showStore()
{
	cout << "Lp \tNazwa \t\tCena \tHP \tDMG\n";
	for(int i = 0; i < this->store.size(); i++)
		cout << i << "\t" << store[i] << "\t" << store[i].getPrice() << "\t" << store[i].getHpBonus() << "\t" << store[i].getDmgBonus() << "\n";
}

Shop::Shop(string text, Player& pl, vector<Item> store):Event(text, pl)
{
	this->text = text;
	this->store = store;
}
