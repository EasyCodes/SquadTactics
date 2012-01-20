#ifndef MAPPACK_H
#define MAPPACK_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class MapPack{
	public:
		MapPack();
		int get_map();
		void load_map(int x);
		void print_map();
		string get_name();
		int get_map_value(int i, int j);
		//void init_BigTest();

	private:
		int mapBigTest[32][48];
		int mapCrossHair[32][48]; 
		int mapZeroPlane[32][48];
		int mapError[32][48];
		int mapSeigeHouse[32][48];
		int map[32][48];

		string MapName;

	
};


#endif