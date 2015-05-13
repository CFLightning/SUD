#include "iostream"
#include "cstdlib"
#include "sud.h"

using namespace std;

int main()
{	
	srand(time(NULL));
	
	Item miecz("Miecz", 15, 2, 0, 2);
	Item luk("Luk", 12, 2, 0, 2);
	Item nusz("Noz", 10, 1, 0, 2);
	
	vector<Item> _items(3);
	_items[0] = miecz;
	_items[1] = luk;
	_items[2] = nusz;
	
	Player antos("Antos", 10, 2, 1, 100);		// bo jesteś kurwa biedakiem
	antos.takeItem(_items[rand() % 3]);
	antos.showEq();
	antos.show();
	antos.equipItem(1);
	antos.showEq();
	antos.showInventory();
	antos.show();
	
	vector<Item> store;
	
	for(int i = 0; i < 10; i++)
		store.push_back(_items[rand() % 3]);
	
	Shop shop(store);
	shop.showStore();
	
	shop.buy(0, antos);
	antos.show();
	antos.showInventory();
	
	shop.sell(2, antos);
	antos.showInventory();
	
	return 0;
}
