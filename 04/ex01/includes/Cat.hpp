#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& other);
	virtual ~Cat();
	Cat& operator=(const Cat& other);

	void	makeSound() const;
	void	readBrain() const;
	void	setIdea(int const index, const str &idea);
	str		getIdea(int const index) const;

protected:

private:
	Brain *_brain;

};
