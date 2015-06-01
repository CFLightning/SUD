#ifndef _character_h_included
#define _character_h_included

#include "string"

using namespace std;

class Character
{
	protected:
		int hp;
		int baseHp;
		int maxHp;
		int baseDmg;
		int dmg;
		int lvl;
		
		string description;
		string name;
		Character(string, int, int, int);

	public:
		void takeDMG(int);
		int getDMG();
		int getMaxHp();
		int getHp();
		int getLvl();
		string getName();
};

#endif
