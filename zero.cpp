#include "zero.h"
#include "string"

bool Zero::isZero()
{
	return true; 
}

Zero::Zero(string text, Player& player):Event(text, player)
{
	text="Nic tu nie ma\n";
}
