#include "interaction.h"

bool Interaction::isInteraction() const
{
	return true;
}

bool Interaction::isBattle() const
{
	return false;
}

bool Interaction::isShop() const
{
	return false;
}

bool Interaction::isZero() const
{
	return false;
}

Interaction::Interaction(string text, Player& player, int bonusHP, int bonusDMG, int DMGamount, int lvlUp, int gold): Event(text, player)
{
	this->text=text;
	this->bonusHP=bonusHP;
	this->bonusDMG=bonusDMG;
	this->DMGamount=DMGamount;
	this->lvlUp=lvlUp;
	this->gold=gold;
}

/*void Interaction::interact(Player& player)
{
	cout << text << "\n";
	player.addGold(this->gold);
	if(this->lvlUp)player.levelUp();
	player.takeDMG(this->DMGamount);
	player.interactionBonus(this->bonusHP, this->bonusDMG);
}*/

