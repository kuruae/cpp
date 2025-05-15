#include "Character.hpp"
#include "setup.hpp"

Character::Character() : _name("default name")
{
	for (int i = 0; i < MAX_INVETORY; i++)
		this->_inventory[i] = NULL;
}

Character::Character(str const& name) : _name(name)
{
	for (int i = 0; i < MAX_INVETORY; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < MAX_INVETORY; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < MAX_INVETORY; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < MAX_INVETORY; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

str const&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < MAX_INVETORY; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
	//delete m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_INVETORY)
		return ;
	if (this->_inventory[idx])
		this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_INVETORY)
		return ;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}