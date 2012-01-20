#ifndef ARMOURCLASS_H
#define ARMOURCLASS_H
#include "STCMD.h"
#include <string>
using namespace std;

class Armour
{	 
  public:
	Armour();
	Armour(int armNum);
	
	void set_armourValue(int x);
	void set_encumberance(int x);
	int get_armourValue() const;
	int get_encumberance() const;
	string get_armourType() const;

  protected:
	string armourType;
	int armour;
	int armourValue, encumberance;
};




#endif