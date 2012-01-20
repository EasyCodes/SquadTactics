#ifndef LOADOUTCLASS_H
#define LOADOUTCLASS_H
#include "STCMD.h"
#include "ArmourClass.h"
#include "GadgetClass.h"
#include "GrenadeClass.h"
#include "WeaponClass.h"
#include <iostream>
#include <string>
using namespace std;






class LoadOut : public Weapon, public Armour, public Gadget, public Grenade
{
public:
	LoadOut();
	LoadOut(int weapNum, int armNum, int gadNum, int greNum);
	/*
	void init_Weapon(int weapNum);
	void init_Armour(int armNum);
	void init_Gadget(int gadNum);
	void init_Grenade(int greNum);
	*/
protected:
	
	int weapNum;
	int armNum;
	int gadNum;
	int greNum;
};

#endif