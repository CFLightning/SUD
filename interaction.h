#ifndef _interaction_h_included
#define _interaction_h_included

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
		Interaction(string, Player&);
		
};


#endif
