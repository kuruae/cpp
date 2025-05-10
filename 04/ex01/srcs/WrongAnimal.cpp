#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->_type = other._type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal assignement operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "no sound" << std::endl;

}

str WrongAnimal::getType() const
{
	return (_type);
}