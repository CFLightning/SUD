#include "event.h"
#include "player.h"
#include "npc.h"

#include "vector"

class Battle: public Event
{
	private:
		Npc enemy;
	public:
		Battle(Player&, Npc&);
		bool isInteraction() const;
		bool isBattle() const;
		bool isZero() const;
		bool isShop() const;
		//virtual int happen(Player&);
};
