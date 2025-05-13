#pragma once

#include <string>
#include <iostream>

typedef std::string str;

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal& other);

	void makeSound() const;
	virtual str getType() const;	

protected:
	str _type;

private:

};