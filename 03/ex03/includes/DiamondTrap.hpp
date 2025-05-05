#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(const str& name);
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& other);

	void	whoAmI();

private:
	str	_name;
};