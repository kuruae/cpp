#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const str& name) : 
_name(name),
_hp(DEFAULT_STATS),
_energy(DEFAULT_STATS),
_ad(DEFAULT_STATS)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor has been called" << std::endl;
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ad = other._ad;
	this->_energy = other._energy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor has been called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ad = other._ad;
		this->_energy = other._energy;
	}
	return (*this);
}

bool ClapTrap::checkEnergy(int toSubstract)
{
	if ((this->_energy - toSubstract) < 0)
	{
		std::cout	<< "ClapTrap " << this->_name
					<< " doesn't have enough energy"
					<< " to perform this action. (" << this->_energy
					<< " energy points remaining)" << std::endl;
		return (false);
	}
	return (true);
}

void ClapTrap::attack(const str& target)
{

	if (checkEnergy(1)) 
	{
		this->_energy--;
		std::cout	<< "ClapTrap " << this->_name <<  " attacks "
					<< target << ", causing " << this->_ad
					<< " points of damage" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout	<< "ClapTrap " << this->_name <<  " takes "
				<< amount << " points of damage! ouch.." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (checkEnergy(1))
	{
		this->_energy--;
		std::cout	<< "ClapTrap " << this->_name << " healed for "
					<< amount << " health points" << std::endl;
	}
}