#pragma once

#include "setup.hpp"

class AMateria
{
public:
	AMateria();
	AMateria(str const& type);
	AMateria(const AMateria& other);
	~AMateria();
	
	AMateria& operator=(const AMateria& other);

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	str _type;

};