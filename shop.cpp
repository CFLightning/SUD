#include "iostream"
#include "shop.h"
#include "item.h"
#include "player.h"

using namespace std;

bool Shop::isShop()
{
	return true;
}

bool Shop::buy(int item, Player player)
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

bool Shop::sell(int item, Item type, Player player)
{
	cout << "Sold item: " << type << "\nNo returns\n";
	
	player.addGold(type.getPrice());
	player.giveItem(item);
	
	return true;
}

void Shop::showStore()
{
	cout << "Lp \tNazwa \tCena \tHP \tDMG\n";
	for(int i = 0; i < this->store.size(); i++)
		cout << i << "\t" << store[i] << "\t" << store[i].getPrice() << "\t" << store[i].getHpBonus() << "\t" << store[i].getDmgBonus() << "\n";
}

Shop::Shop(vector<Item> store)
{
	this->store = store;
}
