#ifndef GRENADECLASS_H
#define GRENADECLASS_H

#include <string>
using namespace std;
	
	
class Grenade
{		
public:
	Grenade();
	Grenade(int greNum);
	void set_greTot(int greTot);
	int get_effNum() const;
	int get_greDam() const;
	int get_expRad() const;
	int get_greTot() const;
	void throw_grenade();
	

protected:
	int greTot, expRad, greDam, greNum, effNum;
	string greName;
/*
For now, Grenades will be 
0-frag  1-incendiary
2-EMP   3-Gas
4-Smoke
any other number results in errorFrag
*/
};


/*
	int explosiveRadius;
	int damage;
	enum effectType{fragEffect, incendiaryEffect, EMPEffect, flashBangEffect};
	enum grenadeType{frag, incendiary, EMP, flashBang};
*/

#endif