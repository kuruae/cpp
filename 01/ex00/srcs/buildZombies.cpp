#include "Zombie.hpp"

void	randomChump( std::string name )
{
	Zombie zomb = Zombie(name);
	zomb.announce();
}

Zombie*	newZombie( std::string name )
{
	Zombie* zomb = new Zombie(name);
	return (zomb);
}
