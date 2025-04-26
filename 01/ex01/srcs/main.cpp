#include "Zombie.hpp"

int main()
{
	Zombie* george = newZombie("George");
	george->announce();
	randomChump("Oui hahahaha");
	delete george;
}