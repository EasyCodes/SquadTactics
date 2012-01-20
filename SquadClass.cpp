#include "SquadClass.h"

Squad::Squad(){ //players control a group (squad) of 4 people (soliders mostly) 
}

void Squad::load_units(Person p[4], int SIZE)
{
	//if (length(p) != SIZE){cout << "Number of squad members not equal to length";}
	cout <<"Loading Persons Into Squad\n";
	for (int i = 0; i < SIZE; i++){
		s[i] = p[i];
		cout <<"Loaded\n";
	}
}	

void Squad::select_unit(int sel)
{
	s[sel].Person::select(true);
}
void Squad::deselect_unit(int sel)
{
	s[sel].Person::select(false);
}

void Squad::set_unit(Person p, int i)
{
	s[i] = p;
}

Person Squad::get_unit(int i)
{
	return s[i];
}

/*
int* Squad::Attack_Move(int brv, int bcv)
{
	Person cmdGrp[4];
	int grpNum = 0;
	int* cmdList;
	int cmdListIndex;


	for (int i = 0; i < 4; i++)
	{
		if (s[i].get_selected() == true)
		{
			cmdGrp[grpNum] = s[i];
			grpNum++;
		}
	}

	for (int i = 0; i < grpNum; i++)
	{
		if (brv > cmdGrp[i].boardRowValue && bcv > cmdGrp[i].boardColumnValue)
		{
			int xdist, ydist;
			xdist = (brv - cmdGrp[i].boardRowValue);
			ydist = (bcv - cmdGrp[i].boardColumnValue);
			//for (i 
			
			
		}


	}
	return cmdList;
}
*/