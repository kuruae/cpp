#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap::ClapTrap() {}

FragTrap::FragTrap(const str& name) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor called" << std::endl;
	this->_hp = FRAG_HP;
	this->_energy = FRAG_ENERGY;
	this->_ad = FRAG_AD;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->_hp = other._hp;
		this->_energy = other._energy;
		this->_ad = other._ad;
	}
	return (*this);
}

void FragTrap::highFiveGuys()
{
	std::cout << "Permission granted, you might high five your friends" << std::endl;
}