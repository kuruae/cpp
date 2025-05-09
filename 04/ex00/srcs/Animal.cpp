#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = other._type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignement operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "no sound" << std::endl;

}

str Animal::getType() const
{
	return (_type);
}