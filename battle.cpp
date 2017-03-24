#include "string"
#include "battle.h"
#include "npc.h"
#include "unistd.h"

Battle::Battle(Player& player, Npc& enemy):Event("You see a " + enemy.getName() + " standing in your way, what do you do?\n", player)
{
	this->text="You see a " + enemy.getName() + " standing in your way, what do you do?";
	this->enemy=enemy;
}

int Battle::fight(Player& player)
{
	#define gameOver cout << "You died. Game over\n"; return 0
	while(true)
	{
		string command;
		
		cout << "You have " << player.getDMG() << "Dmg, and " << player.getHp() << "/" << player.getMaxHp() << "\n";
		cout << "Your enemy has " << enemy.getHp() << "/" << enemy.getMaxHp() 
			 << " Hitpoints! Fight or run?\n";
		cout << "\t> ";
		cin >> command;
		if(command == "fight")
		{
			while(player.getHp()>0)
			{
				enemy.takeDMG(player.getDMG());
				cout << "Your enemy takes " << player.getDMG() 
					 << " damage, he has now " << enemy.getHp() 
					 << "/" << enemy.getMaxHp() << "\n";
					 
				if(enemy.getHp()<1)break;
				
				player.takeDMG(enemy.getDMG());
				cout << "You recieve " << enemy.getDMG() 
					 << " damage from your enemy, you now have " 
					 << player.getHp() << "/" << player.getMaxHp() << "\n";
				
			}			
		}
		else if(command == "run")
		{
			
			if(player.getLvl()>1)
			{
				cout << "You decide to run, you lose a lvl as punishment\n";
				player.levelDown();
				return 2;
			}
			else 
				cout << "Your level is too low to run\n";
		}
		else 
			cout << "Incorrect command, you can either fight or run\n";
		if(player.getHp() <= 0)
		{
			return 0;
		}
		else if(enemy.getHp() <= 0)
		{
			player.takeItem(enemy.dropItem());
			return 1;
		}
	}
}
