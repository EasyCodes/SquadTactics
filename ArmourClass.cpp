#include "ArmourClass.h"

/*
For now, Armour will be 
0-Light  1-Medium
2-Heavy
any other number results in ErrorLight
*/
Armour::Armour()
{

}

Armour::Armour(int armNum)
{
		if (armNum == 0) 
		{
			armourValue = 15;
			encumberance = 0;
			armourType = "Light";
		}
	
		if (armNum == 1) 
		{
			armourValue = 30;
			encumberance = 1;
			armourType = "Medium";
		}
	
		if (armNum == 2) 
		{
			armourValue = 50;
			encumberance = 2;
			armourType = "Heavy";
		}		

		else
		{
			armourValue = 15;
			encumberance = 0;
			armourType = "ErrorLight";
		}
}

void Armour::set_armourValue(int x)
{
		armourValue = x;
}

void Armour::set_encumberance(int x)
{
	encumberance = x;
}

int Armour::get_armourValue() const
{
	return armourValue;
}

int Armour::get_encumberance() const
{
	return encumberance;
}

string Armour::get_armourType() const
{
	return armourType;
}
