#include "GrenadeClass.h"

Grenade::Grenade()
{

}

Grenade::Grenade(int greNum)
{
	
	if (greNum == 0) 
	{
		effNum = 0;
		greDam = 100;
		greName = "frag";
	}
	
	if (greNum == 1)
	{
		effNum = 1;
		greDam = 100;
		greName = "incendiary";
	}
	
	if (greNum == 2) 
	{
		effNum = 2;
		greDam = 100;
		greName = "EMP";
	}
	
	else 
	{
		effNum = 0;
		greDam = 100;
		greName = "errorFrag";
	}
}

void Grenade::set_greTot(int x)
{
	greTot = x;
}

int Grenade::get_effNum() const
{
	return effNum;
}
int Grenade::get_greDam() const
{
	return greDam;
}

int Grenade::get_expRad() const
{
	return expRad;
}


int Grenade::get_greTot() const
{
	return greTot;
}


void Grenade::throw_grenade() 
{
	greTot--;
	/*need throw action happen*/
}

