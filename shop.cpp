#include "iostream"
#include "shop.h"

using namespace std;

bool Shop::isShop()
{
	return true;
}

bool Shop::buy(Item item, Player player)
{
	if(player.getGold() < item.getPrice())
	{	
		cout << "Not enough monies\n";
		
		return false;
	}
	else
	{
		player.spendGold(item.getPrice());
		player.takeItem(item);
		
		return true;
	}
	
	return false;
}

bool Shop::sell(Item item, Player player)
{
	cout << "Sold item: " << item << "\nNo returns\n";
	
	player.addGold(item.getPrice());
	player.giveItem(item);
	
	return true;
}

void Shop::showStore()
{
	for(int i = 0; i < this->store.size(); i++)
		cout << store[i] << "\t" << store[i].getPrice() << "\n";
}
