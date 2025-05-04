#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {

	ClapTrap p1("robot");

	p1.takeDamage(5);
	p1.beRepaired(5);
	p1.attack("John");

	std::cout << "\n\n" << std::endl;

	ScavTrap p2("George");
	p2.guardGate();
	p2.takeDamage(5);
	p2.beRepaired(5);
	p2.attack("John");
	p2.guardGate();

	std::cout << "\n\n" << std::endl;

	FragTrap p3("George");
	p3.takeDamage(5);
	p3.beRepaired(5);
	p3.attack("John");
	p3.highFiveGuys();

	return 0;
}