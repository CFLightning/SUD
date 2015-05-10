#ifndef _character_h_included
#define _character_h_included

#include "string"

using namespace std;

class Character
{
	protected:
		int hp, baseHp, maxHp, baseDmg, dmg, lvl;
		string description, name;
		Character(string, int, int, int);
	public:
		void takeDMG(Character);
		int getDMG();
};

#endif
