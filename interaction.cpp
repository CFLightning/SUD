#include "interaction.h"

Interaction::Interaction(string text, Player& player, int bonusHP, int bonusDMG, int DMGamount, int lvlUp, int gold): Event(text, player)
{
	this->text=text;
	this->bonusHP=bonusHP;
	this->bonusDMG=bonusDMG;
	this->DMGamount=DMGamount;
	this->lvlUp=lvlUp;
	this->gold=gold;
}

void Interaction::interact(Player& player)
{
	cout << text << "\n";
	player.addGold(this->gold);
	if(this->lvlUp)player.levelUp();
	player.takeDMG(this->DMGamount);
	player.interactionBonus(this->bonusHP, this->bonusDMG);
}

