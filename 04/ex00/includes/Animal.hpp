#pragma once

#include <string>
#include <iostream>

typedef std::string str;

class Animal
{
public:
	Animal();
	Animal(const Animal& other);
	virtual ~Animal();
	Animal& operator=(const Animal& other);

	virtual void makeSound() const;
	virtual str getType() const;	

protected:
	str _type;

private:

};