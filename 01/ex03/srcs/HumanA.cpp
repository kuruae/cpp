#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) :
_name(name.empty() ? "Unknown" : name),
_weapon(weapon)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

std::string HumanA::getName() const
{
	return this->_name;
}

void HumanA::setName(std::string name)
{
	this->_name = name;
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}

void HumanA::attack()
{
	std::cout << YEL << this->_name << END" attacks with their "GRN << this->_weapon.getType()
	<< END << std::endl;
}