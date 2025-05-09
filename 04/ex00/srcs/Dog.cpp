#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Animal assignement operator called" << std::endl;
	 if (this != &other)
		Animal::operator=(other);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;

}