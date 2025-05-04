#include "ClapTrap.hpp"

int main( void ) {

	ClapTrap p1("robot");

	p1.takeDamage(5);
	p1.beRepaired(5);

	ClapTrap p3 = p1;

	for (int i = 0; i < 11; i++)
		p1.attack("John");

	ClapTrap p2(p1);

	p2.attack("p1");
	p3.attack("p2");

	return (0);
}