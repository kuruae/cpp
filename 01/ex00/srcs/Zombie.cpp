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

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
