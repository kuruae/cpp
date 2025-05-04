#pragma once

#include "ClapTrap.hpp"

#define RED "\033[0;31m"
#define END "\033[0m"

#define SCAV_HP 100
#define SCAV_ENERGY 50
#define SCAV_AD 20

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const str& name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap();
	
	ScavTrap& operator=(const ScavTrap& other);

	void	guardGate();

private:
	bool	_isGuarding;
};