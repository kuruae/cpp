#include "DiamondTrap.hpp"

int main( void ) {

	ClapTrap p1("robot");

	p1.takeDamage(5);
	p1.beRepaired(5);
	p1.attack("John");

	std::cout << "\n\n" << std::endl;

	ScavTrap p2("George");
	p2.guardGate();
	p2.takeDamage(0);
	p2.beRepaired(8);
	p2.attack("John");
	p2.guardGate();

	std::cout << "\n\n" << std::endl;

	FragTrap p3("John");
	p3.takeDamage(1000);
	p3.beRepaired(20);
	p3.attack("Mathis");
	p3.highFiveGuys();

	std::cout << "----- DIAMOND -----\n\n" << std::endl;

	DiamondTrap p4("Mathis");
	p4.takeDamage(1);
	p4.beRepaired(0);
	p4.attack("robot");
	p4.whoAmI();

	return 0;
}