#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    struct Floor
    {
        AMateria*   materia;
        Floor*      next;
        Floor(AMateria* m);
        ~Floor();
    };

    AMateria*       _inventory[MAX_INVETORY];
    str             _name;
    Floor*          _floorHead;

public:
    Character();
    Character(str const& name);
    Character(const Character& other);
    ~Character();

    Character&      operator=(const Character& other);

    str const&      getName() const;
    void           equip(AMateria* m);
    void           unequip(int idx);
    void           use(int idx, ICharacter& target);
};