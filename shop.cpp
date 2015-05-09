#include "iostream"
#include "shop.h"

using namespace std;

bool Shop::isShop()
{
	return true;
}

bool Shop::buy(Item item, Player player)
{
	if(player.getGold < item.price())
	{	
		cout << "Not enough monies\n";
		
		return false;
	}
	else
	{
		player.spendGold(item.price());
		
		return true;
	}
	
	return false;
}

bool Shop::sell(Item item, Player player)
{
	cout << "Sold item: " << item << "\nNo refunds\n";
	
	player.
}
