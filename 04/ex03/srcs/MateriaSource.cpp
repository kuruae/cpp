#include "MateriaSource.hpp"
#include "Character.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_INVETORY; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < MAX_INVETORY; i++)
    {
        if (other._materia[i])
            this->_materia[i] = other._materia[i]->clone();
        else
            this->_materia[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_INVETORY; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < MAX_INVETORY; i++)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			if (other._materia[i])
				this->_materia[i] = other._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < MAX_INVETORY; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_INVETORY; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	std::cout << "Materia not found" << std::endl;
	return (NULL);
}

