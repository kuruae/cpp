#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& other);
	virtual ~Dog();
	Dog& operator=(const Dog& other);

	void	makeSound() const;
	void	readBrain() const;
	void	setIdea(int const index, const str &idea);
	str		getIdea(int const index) const;

protected:

private:
	Brain *_brain;
};