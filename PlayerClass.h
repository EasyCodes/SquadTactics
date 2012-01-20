#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include "STCMD.h"
#include "CmdNode.h"
#include "CmdList.h"
#include "SquadClass.h"
#include "PersonClass.h"


class Player: public Squad{

  public:
	//Class Initializer
	Player();
	Player(Squad x);

	//Move List Generator
	CmdNode * cmd_Player_move_unit(int p, int x, int y);

	//Player Commands
	void load_squad(Squad s);
	void select_unit(int x);
	void deselect_unit(int x);
	void move_unit(CmdNode * cmdListHead, Person p);
	Squad get_squad();
	Person get_unit(int x);
	

protected:
	int squadSize;
	int arraySize;
	int numPerson;
	Squad s;
};


#endif