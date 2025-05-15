#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(str const& name);
	Character(const Character& other);
	virtual ~Character();

	Character&			operator=(const Character& other);

	str const&			getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
private:
	AMateria*			_inventory[MAX_INVETORY];
	str					_name;
};