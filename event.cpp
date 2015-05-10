#include "event.h"
#include "iostream"

ostream& operator<<(ostream& ostr, const Event& event)
{
	ostr << event.text;
	
	return ostr;
}
