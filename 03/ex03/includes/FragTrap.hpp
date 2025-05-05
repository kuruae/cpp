#pragma once

#include "ClapTrap.hpp"

#define FRAG_HP 100
#define FRAG_ENERGY 100
#define FRAG_AD 30

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const str& name);
	FragTrap(const FragTrap& other);
	~FragTrap();
	
	FragTrap& operator=(const FragTrap& other);

	void	highFiveGuys();
};