#include "WeaponClass.h"

/*
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
*/


/*
For now, weapons will be 
0-Knife  1-Pistol
2-Riffle 3-Machine Gun
4-Sniper 
any other number results in ErrorKnife
*/

Weapon::Weapon()
{
	weaponMaxRange = 1;
	weaponDamage = 100;
	maxAmmo = -1;
	clipAmmo = -1;
	weaponName = "Knife";
}

Weapon::Weapon(int weapNum){
	if (weapNum == 0) {
	weaponMaxRange = 1;
	weaponDamage = 100;
	maxAmmo = -1;
	clipAmmo = -1;
	weaponName = "Knife";
	}
	
	if (weapNum == 1){
	weaponMaxRange = 10;
	weaponDamage = 10;
	maxAmmo = 40;
	clipAmmo = 10;
	weaponName = "Pistol";
	}
	
	if (weapNum == 2) {
	weaponMaxRange = 20;
	weaponDamage = 50;
	maxAmmo = 40;
	clipAmmo = 5;
	weaponName = "Riffle";
	}
	
	if (weapNum == 3) {
	weaponMaxRange = 15;
	weaponDamage = 10;
	maxAmmo = 10;
	clipAmmo = 10;
	weaponName = "Machine Gun";
	}
	
	if (weapNum == 4)  {
	weaponMaxRange = 45;
	weaponDamage = 75;
	maxAmmo = 20;
	clipAmmo = 1;
	weaponName = "Sniper";
	}
	
	else {
	weaponMaxRange = 1;
	weaponDamage = 100;
	maxAmmo = -1;
	clipAmmo = -1;
	weaponName = "ErrorKnife";
	}
}

int Weapon::get_weaponMaxRange() const
{
	return weaponMaxRange;
}
int Weapon::get_weaponDamage() const
{
	return weaponDamage;
}

int Weapon::get_maxAmmo() const
{
	return maxAmmo;
}

int Weapon::get_clipAmmo() const
{
	return clipAmmo;
}

int Weapon::get_weaponType() const
{
	return weaponType;
}
