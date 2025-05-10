#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Animal assignement operator called" << std::endl;
	 if (this != &other)
	 {
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	 }
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;

}

void Cat::readBrain() const
{
	if (this->_brain)
		this->_brain->readBrain();
	else
		std::cout << "brainless cat...." << std::endl;
}