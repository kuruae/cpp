#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& other);
	~Ice();

	Ice&				operator=(const Ice& other);

	void 				use(ICharacter& target);
	virtual AMateria*	clone() const;
};