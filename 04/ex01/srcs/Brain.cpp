#include "Brain.hpp"

Brain::Brain() 
{
	std::cout << "brain constructor" << std::endl;
	// this->_ideas[10] = "this is an idea";
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain() { std::cout << "brain destroyer" << std::endl; }

void Brain::readBrain() const
{
	for (int i = 0; i < 100; i++)
		std::cout << this->_ideas[i] << "\n";
	std::cout << "wow so many ideas" << std::endl;
}