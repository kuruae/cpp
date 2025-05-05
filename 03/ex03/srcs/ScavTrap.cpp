#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap::ClapTrap(), _isGuarding(false) {}

ScavTrap::ScavTrap(const str& name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	this->_hp = SCAV_HP;
	this->_energy = SCAV_ENERGY;
	this->_ad = SCAV_AD;
	this->_isGuarding = false;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	this->_isGuarding = other._isGuarding;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->_hp = other._hp;
		this->_energy = other._energy;
		this->_ad = other._ad;
	}
	return (*this);
}

void ScavTrap::guardGate()
{
	_isGuarding = !_isGuarding;
	if (_isGuarding)
		std::cout << "ScavTrap is now guarding the gate ✅" << std::endl;
	else
	std::cout	<< "ScavTrap is" << RED << " not " << END 
				<< "guarding the gate anymore" << std::endl;
}