#include "Zombie.hpp"

Zombie::Zombie (std::string name) : _name(name)
{
	return;
}

Zombie::~Zombie()
{
	return;
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	newZombie( std::string name )
{
	Zombie* zomb = new Zombie(name);
	return (zomb);
}


void	randomChump( std::string name )
{
	Zombie zomb = Zombie(name);
	zomb.announce();
}