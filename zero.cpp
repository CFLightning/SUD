#include "zero.h"
#include "string"

bool Zero::isZero()
{
	return true; 
}

Zero::Zero(Player& player):Event("Nic tu nie ma\n", player)
{
	;
}
