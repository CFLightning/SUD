#include "event.h"

ostream& operator<<(ostream& ostr, const Event& event)
{
	ostr << event.text;
	
	return ostr;
}
