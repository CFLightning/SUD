#ifndef _zero_h_included
#define _zero_h_included

#include "event.h"

class Zero: public Event
{
	public:
		bool isZero();
		Zero(Player&);
};

#endif
