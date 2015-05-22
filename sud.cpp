#include "sud.h"

#include "fstream"
#include "string"
#include "iostream"
#include "cstdlib"

using namespace std;

bool Sud::init()
{
	fstream f_items;
	f_items.open(_itemsPath, ios::in);
	
	if(f_items.good())
	{
		string name;
		string buffer;
		int args[4];
		
		while(!f_items.eof())
		{
			getline(f_items, name);
			if(name[0] == '{' || name[0] == '}' || name == "" || name[0] == ' ')
				continue;
			for(int i = 0; i < 4; i++)
			{
				getline(f_items, buffer);
				args[i] = atoi(buffer.c_str());
			}
			this->items.push_back(Item(name, args[0], args[1], args[2], args[3]));
			cout << this->items[this->items.size	() - 1] << "\n";
		}	
		f_items.close();
	}
	else
	{
		cout << "Couldn't open _itemsPath file.\n";
		return false;
	}
	
	return true;
}

Item Sud::getItem(int item)
{
	return this->items[item];
}

int Sud::howMuchItems()
{
	return this->items.size();
}
