#include "iostream"
#include "cstdlib"
#include "sud.h"

using namespace std;

int main()
{	
	srand(time(NULL));
	
	Item miecz("Miecz", 10000, 100, 10, 2);
	Item luk("Luk", 10123, 12, 532, 2);
	
	vector<Item> store;
	
	for(int i = 0; i < 10; i++)
	{
		if(rand() % 2)
			store.push_back(miecz);
		else
			store.push_back(luk);
	}
	
	Shop shop(store);
	shop.showStore();
	
	return 0;
}
