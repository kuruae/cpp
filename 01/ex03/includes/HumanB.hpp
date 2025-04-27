#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>

#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB();

	std::string getName() const;
	void setName(std::string name);
	void setWeapon(Weapon &weapon);
	void attack();

private:
	std::string _name;
	Weapon *_weapon;
	bool _hasWeapon;

};