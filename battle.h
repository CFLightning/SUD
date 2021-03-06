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
		int fight(Player&);
};
