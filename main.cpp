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
	
	//Character antos("Antos", 10, 2, 1);
	Player antos("Antos", 10, 2, 1, 0);				// bo jesteś kurwa biedakiem
	antos.takeItem(luk);
	antos.show();
	
	vector<Item> _items(3);
	_items[0] = miecz;
	_items[1] = luk;
	_items[2] = nusz;
	
	vector<Item> store;
	
	for(int i = 0; i < 10; i++)
		store.push_back(_items[rand() % 3]);
	
	Shop shop(store);
	shop.showStore();
	
	return 0;
}
