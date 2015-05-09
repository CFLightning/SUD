#ifndef _character_h_included
#define _character_h_included

#include "string"

using namespace std;

class Character
{
	//virtual void show() = 0;
	protected:
	 int hp, baseHp, maxHp, baseDmg, dmg, lvl;
	 string description, name;
	public:
	 void takeDMG(Character);
	 int getDMG();
	 void show();
};

#endif
