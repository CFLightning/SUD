#ifndef _interaction_h_included
#define _interaction_h_included

#include "string"
#include "event.h"

using namespace std;

class Interaction: public Event
{
	private:
		int bonusHP;
		int bonusDMG; 
		int DMGamount;
		int lvlUp;
		int gold;
	public:
		bool isInteraction() const;
		bool isBattle() const;
		bool isZero() const;
		bool isShop() const;
		Interaction(string, Player&, int, int, int, int, int);
		//virtual int happen(Player&);
};

#endif
