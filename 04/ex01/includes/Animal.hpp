#pragma once

#include <string>
#include <iostream>
#include "Brain.hpp"

typedef std::string str;

class Animal
{
public:
	Animal();
	Animal(const Animal& other);
	virtual ~Animal();
	Animal& operator=(const Animal& other);

	virtual void	makeSound() const;
	virtual str		getType() const;	
	virtual void	readBrain() const;
	virtual void	setIdea(int const index, const str &idea);
	virtual str		getIdea(int const index) const;

protected:
	str _type;

private:

};