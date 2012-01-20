#include "STCMD.h"
#include "PlayerClass.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#define length(a) ( sizeof ( a ) / sizeof ( *a ) )


Player::Player(){ //player class contains commands to control your squad members 
				  //also contains a squad to be controlled

}

Player::Player(Squad x)
{
	//if (length(x.Squad::get_squad()) != y){cout << "Number Players' Units not equal to length";}
	
	this->s = x;
}	

void Player::load_squad(Squad squad)
{
	s = squad;
}

void Player::select_unit(int x)
{
	return s.Squad::select_unit(x);

}
void Player::deselect_unit(int x)
{
	s.Squad::deselect_unit(x);
}

CmdNode * Player::cmd_Player_move_unit(int p, int x, int y)
{ 
	Person temp = s.get_unit(p);

	CmdList * cmdList = new CmdList();
	
	cmdList->addCmd(0);
	cmdList->addCmd(1);
	cmdList->addCmd(2);
	cmdList->addCmd(3);
	cmdList->addCmd(4);
	cmdList->addCmd(5);
	cmdList->addCmd(6);
	cmdList->addCmd(7);
	cmdList->addCmd(8);
	cmdList->addCmd(9);
	

	return cmdList->CmdList::getHead();		
}

Person Player::get_unit(int x)
{
	return s.Squad::get_unit(x);
}
Squad Player::get_squad(){
	return s;
}