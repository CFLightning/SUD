#include "zero.h"
#include "string"

bool Zero::isZero()
{
	return true; 
}

Zero::Zero(Player& player):Event("There's nothing here\n", player)
{
	;
}
