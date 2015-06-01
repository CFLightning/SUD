#ifndef _zero_h_included
#define _zero_h_included

#include "event.h"

class Zero: public Event
{
	public:
		bool isInteraction() const;
		bool isBattle() const;
		bool isZero() const;
		bool isShop() const;
		Zero(Player&);
};

#endif
