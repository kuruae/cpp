#include "Zombie.hpp"

// class methods

Zombie::Zombie (std::string name) : _name(name)
{
	return;
}

Zombie::~Zombie()
{
	std::cout << YEL << this->_name << END " has been destructed" << std::endl;
}

Zombie*	newZombie( std::string name )
{
	Zombie* zomb = new Zombie(name);
	return (zomb);
}
