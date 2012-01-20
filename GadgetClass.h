#ifndef GADGETCLASS_H
#define GADGETCLASS_H
#include "STCMD.h"
#include <string>
using namespace std;


void Gadget(int gadNum);
int get_gadEff();
string get_gadNam();

class Gadget{
public:
	Gadget();
	Gadget(int gadNum);
	int get_gadEff();
	string get_gadNam();

protected:
	int gadNum;
	int gadEff;
	string gadName;
};

/*
int gadNum;
int gadEffect;
string gadName;
*/
#endif