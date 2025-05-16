#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
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

void Dog::readBrain() const
{
	this->_brain->readBrain();
}

void Dog::setIdea(int const index, const str &idea)
{
	this->_brain->setIdea(index, idea);
}

str Dog::getIdea(int const index) const
{
	return this->_brain->getIdea(index);
}