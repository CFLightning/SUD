#ifndef _event_h_included
#define _event_h_included

#include "player.h"

#include "iostream"
#include "string"

using namespace std;

class Event
{
	protected:
		Player pl;
		string text;
		virtual bool whichEvent;
	
	public:
		friend ostream& operator<<(ostream&, const Event&);
		Event(string, Player&);
		Event();
		virtual bool isInteraction();
		virtual bool isBattle();
		virtual bool isZero() const;
		virtual bool isShop() const;
};

#endif
