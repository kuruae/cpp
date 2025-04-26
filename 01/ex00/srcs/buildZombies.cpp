#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


void	randomChump( std::string name )
{
	Zombie zomb = Zombie(name);
	zomb.announce();
}