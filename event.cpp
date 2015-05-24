#include "event.h"
#include "player.h"

#include "iostream"

ostream& operator<<(ostream& ostr, const Event& event)
{
	ostr << event.text;
	
	return ostr;
}

Event::Event(string text, Player& pl)
{
	this->pl = pl;
	this->text = text;
}
