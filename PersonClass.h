#ifndef PERSONCLASS_H
#define PERSONCLASS_H
#include "LoadOutClass.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Person: public LoadOut{ //soldier class

  public:
	Person();
	string cmdIdentify();

	void set_boardPosition(int, int);
	void set_alive(bool);
	void set_stats(int, int, int, int);
	void set_life(int, int);
	void set_stress(int);
	void set_sightDistance(int);
	void select(bool);
	void set_squadNum(int);
	bool get_selected();
	bool get_alive();
	int get_boardRowValue();
	int get_boardColumnValue(); 
	int get_maxLife();
	int get_life();
	int get_stress();
	int get_sightDistance();
	int get_squadNum();
	
	LoadOut l;
	bool alive, selected;
	int boardRowValue, boardColumnValue, 
		maxLife, life, stress, 
		sightDistance, 
		squadNum;

  protected:
	
};


#endif