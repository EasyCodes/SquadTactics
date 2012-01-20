#include "GadgetClass.h"

/*
For now, gadgets will be 
0-cloak  1-rockets
2-sentry 3-teleporter
4-sprint 
any other number results in errorCloak
*/
Gadget::Gadget()
{

}

Gadget::Gadget(int gadNum)
{
	
	if (gadNum == 0) 
	{
		gadEff = 0;
		gadName = "cloak";
	}
	
	if (gadNum == 1)
	{
		gadEff = 1;
		gadName = "rockets";
	}
	
	if (gadNum == 2) 
	{
		gadEff = 2;
		gadName = "sentry";
	}
	
	else 
	{
		gadEff = 0;
		gadName = "errorCloack";
	}
}

int Gadget::get_gadEff(){
	return gadEff;
}