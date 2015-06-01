#include "sud.h"
#include "player.h"
#include "character.h"
#include "event.h"
#include "npc.h"
#include "item.h"
#include "shop.h"

#include "fstream"
#include "sstream"
#include "string"
#include "iostream"
#include "cstdlib"

using namespace std;

bool Sud::init()
{
		// Loading items
	fstream f_items;
	f_items.open(_itemsPath, ios::in);
	
	if(f_items.good())
	{
		string name;
		string buffer;
		int args[4];
		
		this->items.push_back(Item());
		
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
		}	
		f_items.close();
	}
	else
	{
		cout << "Couldn't open _itemsPath file.\n";
		return false;
	}
	
		// Loading NPCs
	fstream f_npcs;
	f_npcs.open(_npcsPath, ios::in);
	
	if(f_npcs.good())
	{
		string name;
		string buffer;
		int args[3];
		
		while(!f_npcs.eof())
		{
			getline(f_npcs, name);
			if(name[0] == '{' || name[0] == '}' || name == "" || name[0] == ' ')
				continue;
			for(int i = 0; i < 3; i++)
			{
				getline(f_npcs, buffer);
				args[i] = atoi(buffer.c_str());
			}
			this->enemies.push_back(Npc(name, args[0], args[1], args[2], this->getItem(rand() % this->howMuchItems())));
		}	
		f_npcs.close();
	}
	else
	{
		cout << "Couldn't open _npcsPath file.\n";
		return false;
	}
	
		// Loading events
	//...
	
		// Creating map
	for(int x = 0; x < _map_size_x; x++)
	{
		this->map.push_back(vector<Event>());
		
		for(int y = 0; y < _map_size_y; y++)
		{
			stringstream ss;
			ss << "Nic " << x << ", " << y << "\n";
			
			this->map[x].push_back(Event(ss.str(), this->pl));
		}
	}
	
	this->debug_mode = false;
	this->traveled = true;
	
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

int Sud::findItemByName(string name)
{
	for(int i = 0; i < this->items.size(); i++)
	{
		if(this->items[i].getName() == name)
			return i;
	}
	return 0;
}

bool Sud::start()
{
	srand(time(NULL));
	#define player this->pl
	#define _items this->items
	#define start_x 1
	#define start_y 1
	#define inc_comm "Incorrect command, type help if need help\n"
	#define pointless "There is nothing out there; going in this direction is pointless\n"
	#define gameOver cout << "You died. Game over\n"; return 0
	
	string name;
	
	for(int i = 0; i < 50; i++)
		cout << "\n";
	
	cout << "Name: ";
	getline(cin, name);
	
	player = Player(name, 10, 5, 0, 10);
	
	cout << "\nWelcome to the world of SUD, " << player.getName() << "\nYou have been blessed by Fortune!\n";
	player.takeItem(this->getItem(rand() % this->howMuchItems()));
	
	this->currentEvent = map[start_x][start_y];						// Sets starting location
	this->currentPosX = start_x;
	this->currentPosY = start_y;
	
	while(true)
	{
		if(this->traveled)
		{
			cout << this->currentEvent;
			this->traveled = false;
		}
		
		cout << "\t> ";
		string command;
		cin >> command;
		
		// Player
		
		if(command == "show")
		{
			cin >> command;
			
			if(command == "inv")
				player.showInventory();
			else if(command == "eq")
				player.showEq();
			else if(command == "stats")
				player.show();
			else if(command == "item")
			{
				cin >> command;
				if(command == "stats")
				{
					int item;
					cin >> item;
					cout << player.getItemFromInventory(item) 
						<< "\nAttack bonus: " << player.getItemFromInventory(item).getDmgBonus()
						<< "\nHealth bonus: " << player.getItemFromInventory(item).getHpBonus()
						<< "\nPrice: " << player.getItemFromInventory(item).getPrice()
						<< "\n";
				}
				else if(command == "help")
					cout << "Type item index. Index can be checked using show inv\n";
				else
					cout << inc_comm;
			}
			else if(command == "help")
				cout << "inv eq stats item\n";
			else
				cout << inc_comm;
		}
		else if(command == "equip")
		{
			cin >> command;
			if(command == "help")
				cout << "Type item index. Index can be checked using show inv\n";
			else
			{
				if(player.equipItem(atoi(command.c_str())))
					cout << "Succesfully equipped " << player.getItemFromInventory(atoi(command.c_str())) << "\n";
				else
					cout << "Incorrect item index\n";
			}
		}
		else if(command == "dequip")
		{
			cin >> command;
			if(command == "head")
				player.dequipItem(0);
			else if(command == "chest")
				player.dequipItem(1);
			else if(command == "weapon")
				player.dequipItem(2);
			else
				cout << "Incorrect slot\n";
		}
		else if(command == "hurt")
		{
			cin >> command;
			if(command == "me")
			{
				cin >> command;
				int dmg = atoi(command.c_str());
				if(dmg < 0)
				{
					cout << "You tried to cheat. Now you will receive punishment!\n";
					player.takeDMG(-(2 * dmg));
				}
				else
					player.takeDMG(dmg);
				
				if(player.getHp() <= 0)
				{
					gameOver;
				}
			}
			else if(command == "help")
				cout << "Type person whom you want to hurt. Unfortunately, you can only hurt yourself\n";
			else
				cout << inc_comm;
		}
		
		// Movement
		
		else if(command == "go")
		{
			if(this->currentEvent.canTravel())
			{
				cin >> command;
				if(command == "w" || command == "west")
				{
					if(this->currentPosX > 0)
					{
						this->currentEvent = map[--this->currentPosX][this->currentPosY];
						this->traveled = true;
					}
					else
						cout << pointless;
				}
				else if(command == "n" || command == "north")
				{
					if(this->currentPosY < _map_size_y - 1)
					{
						this->currentEvent = map[this->currentPosX][++this->currentPosY];
						this->traveled = true;
					}
					else
						cout << pointless;
				}
				else if(command == "e" || command == "east")
				{
					if(this->currentPosX < _map_size_x - 1)
					{
						this->currentEvent = map[++this->currentPosX][this->currentPosY];
						this->traveled = true;
					}
					else
						cout << pointless;
				}
				else if(command == "s" || command == "south")
				{
					if(this->currentPosY > 0)
					{
						this->currentEvent = map[this->currentPosX][--this->currentPosY];
						this->traveled = true;
					}
					else
						cout << pointless;
				}
				else if(command == "help")
					cout << "Type direction: east, south, west or north\n";
				else
					cout << inc_comm;
			}
			else
				cout << "Cannot travel right now\n";
		}
		
		// CHEATS
		
		else if(command == "heal" && this->debug_mode)
		{
			cin >> command;
			if(command == "me")
				player.takeDMG(-(player.getMaxHp() - player.getHp()));
			else
				cout << inc_comm;
		}
		else if(command == "give")
		{
			cin >> command;
			if(command == "item")
			{
				cin >> command;
				if(command == "%")
				{
					cin >> command;
					player.takeItem(_items[atoi(command.c_str())]);
				}
				else
				{
					player.takeItem(_items[this->findItemByName(command)]);
				}
			}
		}
		else if(command == "debug_mode")
		{
			cin >> this->debug_mode;
		}
		else if(command == "help")
			cout << "show equip dequip hurt go\n";
		else if(command == "suicide")
		{
			cout << "You commit suicide. No more pain.\n";
			return false;
		}
		else
			cout << inc_comm;
	}
	#undef player
	return true;
}
