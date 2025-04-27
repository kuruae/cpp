#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
_name(name.empty() ? "Unknown" : name),
_hasWeapon(false)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

std::string HumanB::getName() const
{
	return this->_name;
}

void HumanB::setName(std::string name)
{
	this->_name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	this->_hasWeapon = true;
}

void HumanB::attack()
{
	if (this->_hasWeapon)
		std::cout << YEL << this->_name << END" attacks with their "GRN 
		<< this->_weapon->getType()
		<< END << std::endl;
	else
		std::cout << YEL << this->_name << END" has no weapon to attack with" << std::endl;
}