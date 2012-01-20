#ifndef WEAPONCLASS_H
#define WEAPONCLASS_H
#include "STCMD.h"
#include <string>
using namespace std;

class Weapon {
  public:
	Weapon();
	

	Weapon(int weapNum);

	int get_weaponMaxRange() const;
	int get_weaponDamage() const;
	int get_maxAmmo() const;
	int get_clipAmmo() const;
	int get_weaponType() const;
	int weapNum, weaponMaxRange, weaponDamage, maxAmmo, clipAmmo, weaponType;
	string weaponName;
protected:

};

/*
int weapNum, weaponMaxRange, weaponDamage, maxAmmo, clipAmmo, weaponType;
string weaponName;
*/

#endif