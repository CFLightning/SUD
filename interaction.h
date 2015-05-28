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
		bool isInteraction();
		Interaction(string, Player&, int, int, int, int, int);
		void interact(Player&);
};

#endif
