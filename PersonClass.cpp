#include "STCMD.h"
#include "LoadOutClass.h"
#include "PersonClass.h"


Person::Person()//soldier class
{
	
}

string Person::cmdIdentify()
{
	std::stringstream identity;
	identity <<"p"<<squadNum;
	return identity.str();
}

void Person::set_boardPosition(int x, int y){
	boardRowValue = x;
	boardColumnValue = y;
}


void Person::set_alive(bool x){
	alive = x;
}

void Person::set_stats(int w, int x, int y, int z){
	maxLife = w;
	life = x;
	stress = y;
	sightDistance = z;
}

void Person::set_life(int x, int y){
	maxLife = x;
	life = y;
}

void Person::set_stress(int x)
{
	stress = x;
}

void Person::set_sightDistance(int x)
{
	sightDistance = x;
}

void Person::set_squadNum(int x)
{
	squadNum = x;
}

void Person::select(bool b){
	selected = b;
}

bool Person::get_selected()
{
	return selected;
}

bool Person::get_alive(){
	return alive;
}

int Person::get_boardRowValue(){
	return boardRowValue;
}

int Person::get_boardColumnValue(){
	return boardColumnValue;
}

int Person::get_maxLife(){
	return maxLife; 
}

int Person::get_life(){
	return life;
}

int Person::get_stress(){
	return stress;
}

int Person::get_sightDistance(){
	return sightDistance;
}
int Person::get_squadNum()
{
	return squadNum;
}


