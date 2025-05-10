#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
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