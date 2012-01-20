#ifndef GAMECLASS_H
#define GAMECLASS_H
#include "STCMD.h"
#include "MapPack.h"
#include "Time.h"
#include "CmdNode.h"
#include "CmdList.h"
#include "PlayerClass.h"
#include "SquadClass.h"
#include "PersonClass.h"
#include <iostream>
#include <fstream>
#include <list>
#define length(a) ( sizeof ( a ) / sizeof ( *a ) )
using namespace std;

class Game{
public:	 
	Game();
	CmdNode * cmd_move(Person p, int x, int y);
	Player get_player(int x);
	Person get_person(int x);
	Squad get_squad(int x);
	Person * get_population();
	
	virtual void Setup(int mapSelection);
	void new_tile();
	void spawn_unit(Person p);
	void set_squad(Squad s, int x);
	void set_tile(int x, int y, int z);
	void set_board_value(int x, int y, int z);
	void init_pop();
	void load_player(Player p, int x);
	void load_population(Person p[], int pop);
	void move_unit(CmdNode * cmdListHead, Person p, int t);
	bool is_free(int, int);
	int Start(void * arg);
	int get_board_value(int x, int y);
	int get_time();
	
protected:
	//Thread Commands
	static void EntryPoint(void*);
	virtual void Execute(void*);
	void * Arg() const {return Arg_;}
	void Arg(void* a){Arg_ = a;}

private:
	
	//Thread Variables
	int ThreadId_;
	void * Arg_;

	//Game Variables
	int board[32][48];
	int tile[32][48];
	int moveNum;
	string mapPath;
	Player player[2];
	Squad squad[2];
	Person pop[8];
	Person pop0[4];
	Person pop1[4];

	
};
#endif