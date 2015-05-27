#include "interaction.h"

bool Interaction::isInteraction()
{
	return true;
}

Interaction::Interaction(string text, Player& player, 
	int bonusHP, int bonusDMG, int DMGamount, int lvlUp, int gold): Event(text, player)
{
	this->text=text;
	this->bonusHP=bonusHP;
	this->bonusDMG=bonusDMG;
	this->DMGamount=DMGamount;
	this->lvlUp=lvlUp;
	this->gold=gold;
}
