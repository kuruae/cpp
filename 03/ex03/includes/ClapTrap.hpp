#pragma once

#include <iostream>
#include <string>

#define CLAP_HP 10
#define CLAP_ENERGY 10
#define CLAP_AD 0

typedef std::string str;

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const str& name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& other);

	void	attack(const str& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:
	str		_name;
	int		_hp;
	int		_energy;
	int		_ad;
	bool	checkEnergy(int toSubstract);
	bool	checkHealth();
};