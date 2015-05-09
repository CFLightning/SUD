#ifndef _event_h_included
#define _event_h_included

#include "iostream"
#include "string"

using namespace std;

class Event
{
	private:
		string text;
	
	public:
		friend ostream& operator<<(ostream&, const Event&);
		int result() = 0;
};

#endif
