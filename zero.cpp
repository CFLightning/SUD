#include "zero.h"
#include "string"

bool Zero::isZero() const
{
	return true; 
}

bool Zero::isShop() const
{
	return false;
}

bool Zero::isBattle() const
{
	return false;
}

bool Zero::isInteraction() const
{
	return false;
}

Zero::Zero(Player& player):Event("There's nothing here\n", player)
{
	;
}

