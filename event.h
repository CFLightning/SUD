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
		bool travel;
	
	public:
		friend ostream& operator<<(ostream&, const Event&);
		Event(string, Player&);
		Event();
		bool canTravel();
		//int result() = 0;
};

#endif
