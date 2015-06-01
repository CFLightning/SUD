#include "string"
#include "battle.h"
#include "npc.h"
#include "unistd.h"

bool Battle::isBattle() const
{
	return true;
}

bool Battle::isShop() const
{
	return false;
}
 
bool Battle::isZero() const
{
	return false;
}

bool Battle::isInteraction() const
{
	return false;
}

Battle::Battle(Player& player, Npc& enemy):Event("You see a " + enemy.getName() + " standing in your way, what do you do?\n", player)
{
	this->text="You see a " + enemy.getName() + " standing in your way, what do you do?";
	this->enemy=enemy;
}

/*int Battle::fight(Player& player)
{
	#define gameOver cout << "You died. Game over\n"; return 0
	while(true)
	{
		string command;
		cout << "Your enemy has " << enemy.getHp() << "/" << enemy.getMaxHp() 
			 << "Fight or run?\n";
		cin >> command;
		if(command == "fight")
		{
			while(player.getHp())
			{
				enemy.takeDMG(player.getDMG());
				cout << "Your enemy takes " << player.getDMG() 
					 << " damage, he has now " << enemy.getHp() 
					 << "/" << enemy.getMaxHp() << "\n";
					 
				if(enemy.getHp())break;
				
				player.takeDMG(enemy.getDMG());
				cout << "You recieve " << enemy.getDMG() 
					 << " damage from your enemy, you now have" 
					 << player.getHp() << "/" << player.getMaxHp() << "\n";
				
			}			
		}
		else if(command == "run")
		{
			cout << "You decide to run, you lose a lvl as punishment\n";
			if(player.getLvl()-1)
			{
				player.levelDown();
				return false;
			}
			else 
				cout << "Your level is too low to run\n";
		}
		if(player.getHp() <= 0)
		{
			return 0;
		}
		else if(enemy.getHp() <= 0)
		{
			return 1;
			player.takeItem(enemy.dropItem(player));
		}
	}
}*/
