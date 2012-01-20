#include "LoadOutClass.h"

LoadOut::LoadOut()
{

}

LoadOut::LoadOut(int weapNum, int armNum, int gadNum, int greNum): Weapon(weapNum), Armour(armNum), Gadget(gadNum), Grenade(greNum)
{

}


/*
void LoadOut::init_Weapon(int weapNum)
{
	Weapon weap.Weapon(weapNum);
}

void LoadOut::init_Armour(int armNum)
{
	Armour arm.Armour(armNum);
}

void LoadOut::init_Gadget(int gadNum)
{
	gad = gad.Gadget(gadNum);
}

void LoadOut::init_Grenade(int greNum)
{
	gre = gre.Grenade(greNum);
}
*/