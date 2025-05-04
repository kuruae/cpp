#pragma once

#include <iostream>
#include <string>

typedef std::string str;
#define DEFAULT_STATS 10

class ClapTrap
{
public:
	ClapTrap(const str& name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& other);

	void	attack(const str& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	str		_name;
	int		_hp;
	int		_energy;
	int		_ad;
	bool	checkEnergy(int toSubstract);
};