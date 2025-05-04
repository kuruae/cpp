#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {

	ClapTrap p1("robot");

	p1.takeDamage(5);
	p1.beRepaired(5);
	p1.attack("John");

	ScavTrap p2("George");
	p2.guardGate();
	p2.takeDamage(5);
	p2.beRepaired(5);
	p2.attack("John");
	p2.guardGate();

	return 0;
}