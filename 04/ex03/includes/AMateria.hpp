#pragma once

#include "setup.hpp"

class AMateria
{
public:
	AMateria();
	AMateria(str const& type);
	AMateria(const AMateria& other);
	virtual ~AMateria();
	
	AMateria& 			operator=(const AMateria& other);

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
	str const&			getType() const;

protected:
	str 				_type;

};