#include "string"
#include "battle.h"
#include "npc.h"

bool Battle::isBattle()
{
	return true;
}

Battle::Battle(string text, Player& player, Npc& enemy):Event(text, player)
{
	this->text="You see a " + enemy.getName() + " standing in your way, what do you do?";
	this->enemy=enemy;
}


