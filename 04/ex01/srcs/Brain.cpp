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

void Brain::setIdea(int const index, const str &idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}

str Brain::getIdea(int const index) const
{
	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return (this->_ideas[0]);
}

