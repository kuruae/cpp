#include "Character.hpp"
#include "setup.hpp"

// initializing the floor
Character::Floor::Floor(AMateria* m) : materia(m), next(NULL) {}
Character::Floor::~Floor() {}
// wow now we have a floor to walk on


Character::Character() : _name("default name"), _floorHead(NULL)
{
	for (int i = 0; i < MAX_INVETORY; i++)
		this->_inventory[i] = NULL;
}

Character::Character(str const& name) : _name(name), _floorHead(NULL)
{
	for (int i = 0; i < MAX_INVETORY; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name), _floorHead(NULL)
{
    for (int i = 0; i < MAX_INVETORY; i++)
        this->_inventory[i] = NULL;

    for (int i = 0; i < MAX_INVETORY; i++)
    {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
    
    // Deep copy floor list
    if (other._floorHead)
    {
        Floor* otherCurrent = other._floorHead;
        this->_floorHead = new Floor(otherCurrent->materia->clone());
        Floor* thisCurrent = this->_floorHead;
        
        while (otherCurrent->next)
        {
            otherCurrent = otherCurrent->next;
            thisCurrent->next = new Floor(otherCurrent->materia->clone());
            thisCurrent = thisCurrent->next;
        }
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

	Floor* current = this->_floorHead;
	while (current)
	{
		Floor* next = current->next;
        if (current->materia)
		{
            delete current->materia;
            current->materia = NULL;
        }
		delete current;
		current = next;
	}
	this->_floorHead = NULL;
}

Character&	Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        
        // Clear current inventory
        for (int i = 0; i < MAX_INVETORY; i++)
        {
            if (this->_inventory[i])
            {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
        }
        
        // Copy new inventory
        for (int i = 0; i < MAX_INVETORY; i++)
        {
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
        }
        
        // Clear current floor list
        Floor* current = this->_floorHead;
        while (current)
        {
            Floor* next = current->next;
            if (current->materia)
            {
                delete current->materia;
                current->materia = NULL;
            }
            delete current;
            current = next;
        }
        this->_floorHead = NULL;
        
        // Deep copy floor list
        if (other._floorHead)
        {
            Floor* otherCurrent = other._floorHead;
            this->_floorHead = new Floor(otherCurrent->materia->clone());
            Floor* thisCurrent = this->_floorHead;
            
            while (otherCurrent->next)
            {
                otherCurrent = otherCurrent->next;
                thisCurrent->next = new Floor(otherCurrent->materia->clone());
                thisCurrent = thisCurrent->next;
            }
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
    if (!m)
    {
        return ;
    }

	for (int i = 0; i < MAX_INVETORY; i++)
	{
	    if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}

	std::cout << "Inventory is full, dropping the Materia." << std::endl;

	if (this->_floorHead == NULL)
	{
		this->_floorHead = new Floor(m);
	}
	else
	{
		Floor* current = this->_floorHead;
		while (current->next)
			current = current->next;
		current->next = new Floor(m);
	}
	std::cout << "Materia " << m->getType() << " dropped on the floor." << std::endl;
	// Note: The Materia is not deleted here, as it is now managed by the linked list
	// and will be deleted in the destructor.
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= MAX_INVETORY || !this->_inventory[idx])
        return;

    AMateria* unequipped = this->_inventory[idx];
    this->_inventory[idx] = NULL;

    // Add to floor list
    Floor* newFloor = new Floor(unequipped);
    if (!this->_floorHead)
    {
        this->_floorHead = newFloor;
    }
    else
    {
        Floor* current = this->_floorHead;
        while (current->next)
            current = current->next;
        current->next = newFloor;
    }
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_INVETORY || !this->_inventory[idx])
		return;
		
	this->_inventory[idx]->use(target);
}