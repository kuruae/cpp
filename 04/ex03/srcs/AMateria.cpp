#include "AMateria.hpp"
#include "setup.hpp"


AMateria::AMateria() : _type("default magic") {}

AMateria::AMateria(str const& type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

const str& AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}