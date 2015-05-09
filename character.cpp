#include "character.h"
#include "string"

using namespace std;

void Character::takeDMG(character enemy)
{
	this->hp -= enemy.getDMG();
}
