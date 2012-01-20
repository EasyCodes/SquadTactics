#include "STCMD.h"
#include "CmdNode.h"
#include "CmdList.h"
#include "GameClass.h"
#include "PlayerClass.h"
#include "PersonClass.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int numPlayers = 8;
void init_game(Game g);
void print_board(Game g, int ticks);




int main(int argc, const char* argv[]){
/******************************************************************/
/***************************START GAME TIME************************/
/******************************************************************/
Game g;
int t = 0;


/******************************************************************/
/***************************INITIALIZE GAME************************/
/******************************************************************/
cout <<"Initializing Game\n";
g.Game::Game();
cout <<"Setting Up Game\n";

/******************************************************************/
/*************************INITIALIZE PEOPLE************************/
/******************************************************************/
g.Game::Setup(3);
cout <<"Game Board Populated  \n\n *************** \n \n";

/******************************************************************/
/****************************LOAD PLAYERS**************************/
/******************************************************************/

Player p1,p0;
cout <<"Initializing Player 1\n";
p0.Player::Player(g.Game::get_squad(0));
cout <<"Initializing Player 2\n";
p1.Player::Player(g.Game::get_squad(1));


g.Game::move_unit(p0.Player::cmd_Player_move_unit(0,0,0),p0.Player::get_unit(0),t );

/******************************************************************/
/***************************PRINT WORLD****************************/
/******************************************************************/
cout <<"Entering Game Loop";

while ( 1>0)
{
	wait(1);							//GET READY
	print_board(g,t);  //GO!
	t++;
}

	
}
void init_game(Game g)
{
	cout <<"Initializing\n";
	g.Game::init_pop();
	cout <<"Populate Game Board \n";
	g.Game::load_population(g.get_population(),8);
	cout <<"Game Board Populated  \n\n *************** \n \n";
}

void print_board(Game g, int moveNum)
{	
		cout << "Print Loop \n";
		if (moveNum == 0){cout <<"First Print\n";}
		cout << "Printing Board: \n\n *************** \n \n";

		
		//0 =   = free
		//1 = X = person
		//2 = W = wall
		//3 = L = ledge
		//e = E = error


		for (int i = 0; i < 32; i++) 
		{
			for (int j = 0; j < 48; j++) //1,2 = Red, Blue
			{
				if (g.Game::get_board_value(i,j) == 0)
				{
					cout << "[ ]";
				}
				if (g.Game::get_board_value(i,j) == 1)//Red Squad
				{
					cout << "[X]";
				}
				if (g.Game::get_board_value(i,j) == 2)//Blue Squad
				{
					cout << "[Y]";
				}
				if (g.Game::get_board_value(i,j) == 3)//Wall
				{
					cout << "[W]";
				}
				if (g.Game::get_board_value(i,j) == 4)//Ledge
				{
					cout << "[L]";
				}
				if (g.Game::get_board_value(i,j) > 4 || (g.Game::get_board_value(i,j) < 0))//Error
				{
					cout << "[E]";
				}

				if (j == 47)
				{
					cout << "\n";
				}		
			}
		}
		
		cout << "Board Print SUCCESS\n";
		wait(3);
		cout <<"Print Number: " << moveNum << "\n";
		if (moveNum == 100){cout << " Game over \n";}
}

/*
	cout <<"Game Variable Initialized \n\n *************** \n \n";
	cout <<"Start  \n\n *************** \n \n";
	cout <<"Create Game Variable\n";
	cout <<"Game Variable Created \n\n *************** \n \n";
	cout <<"Initialize Game Variable\n";	 
	cout <<"Populate Game Board \n";
	cout <<"Game Board Populated  \n\n *************** \n \n";
	cout<<"Begining Game World \n\n *************** \n \n";
*/