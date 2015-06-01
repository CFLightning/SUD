#include "event.h"
#include "player.h"
#include "npc.h"

#include "vector"

class Battle: public Event
{
	private:
		Npc enemy;
	public:
		Battle(string, Player&, Npc&);
		bool isBattle();
		void fight();
};
