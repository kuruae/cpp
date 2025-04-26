#include "Zombie.hpp"

int main()
{
	Zombie* george = newZombie("George");
	george->announce();
	delete george;
	randomChump("Oui hahahaha");
}