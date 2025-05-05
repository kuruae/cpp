#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : 
ClapTrap("unknown_clap_name"),
ScavTrap("unknown"),
FragTrap("unknown"),
_name("unknown")
{
	std::cout << "DiamonTrap Constructor called" << std::endl;
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_ad = FragTrap::_ad;
}

DiamondTrap::DiamondTrap(const str& name) : 
ClapTrap(name + "_clap_name"),
ScavTrap(name),
FragTrap(name),
_name(name)
{
	std::cout << "DiamonTrap Constructor called" << std::endl;
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_ad = FragTrap::_ad;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
ScavTrap(other), FragTrap(other) {}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamonTrap Destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		this->_hp = other._hp;
		this->_energy = other._energy;
		this->_ad = other._ad;
	}
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout	<< "ClapTrap name:" << ClapTrap::_name << "\n"
				<< "DiamondTrap name:" << this->_name << std::endl;
}