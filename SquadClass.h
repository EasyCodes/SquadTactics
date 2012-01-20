//players control a group (squad) of 4 people (soliders mostly)
#ifndef SQUADCLASS_H
#define SQUADCLASS_H
#include "STCMD.h"
#include "PersonClass.h"
#include <string>
using namespace std;

class Squad: public Person{

  public:
	Squad();
	void load_units(Person p[4], int SIZE);
	void select_unit(int sel);
	void deselect_unit(int sel);
	void set_unit(Person p, int i);
	Person get_unit(int i);
	

private:
	int squadSize;
	int arraySize;
	int numPerson;
	Person s[4]; //Array of your units
};


#endif