#include "sud.h"
#include "player.h"
#include "character.h"
#include "event.h"
#include "npc.h"
#include "item.h"
#include "shop.h"

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
			//cout << this->items[this->items.size	() - 1] << "\n";
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

bool Sud::start()
{
	srand(time(NULL));
	#define player this->pl
	
	string name;
	
	for(int i = 0; i < 50; i++)
		cout << "\n";
	
	cout << "Name: ";
	cin.getline(name, 255);
	
	player = Player(name, 10, 5, 0, 10);
	
	cout << "\nWelcome to the world of SUD, " << player.getName() << "\nYou have been blessed by Fortune!\n";
	player.takeItem(this->getItem(rand() % this->howMuchItems()));
	
	while(true)
	{
		cout << "\t> ";
		string command;
		cin >> command;
		
		if(command == "show")
		{
			cin >> command;
			
			if(command == "inv")
				player.showInventory();
			else if(command == "eq")
				player.showEq();
			else if(command == "stats")
				player.show();
			else
				cout << "Incorrect command\n";
		}
		else if(command == "equip")
		{
			int item;
			cin >> item;
			
			if(player.equipItem(item))
				cout << "Succesfully equipped " << player.getItemFromInventory(item) << "\n";
			else
				cout << "Incorrect item index\n";
		}
			
		else if(command == "suicide")
		{
			cout << "You commit suicide. No more pain.\n";
			return false;
		}
		else
			cout << "Incorrect command\n";
	}
	#undef player
	return true;
}
