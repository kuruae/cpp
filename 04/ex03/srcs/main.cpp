#include "setup.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void testBasicFunctionality() {
    std::cout << "\n===== BASIC FUNCTIONALITY TEST (Subject Example) =====\n" << std::endl;
    
    // Create a MateriaSource and teach it some Materias
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // Create a Character
    ICharacter* me = new Character("me");
    
    // Create and equip Materias
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    // Create another Character for targeting
    ICharacter* bob = new Character("bob");
    
    // Use equipped Materias
    std::cout << "Using equipped Materias:" << std::endl;
    me->use(0, *bob); // Should output: * shoots an ice bolt at bob *
    me->use(1, *bob); // Should output: * heals bob's wounds *
    
    // Clean up
    delete bob;
    delete me;
    delete src;
}

void testMateriaSource() {
    std::cout << "\n===== MATERIA SOURCE TEST =====\n" << std::endl;
    
    // Create a MateriaSource
    std::cout << "Creating MateriaSource..." << std::endl;
    IMateriaSource* src = new MateriaSource();
    
    // Test learning Materias
    std::cout << "\nTesting learnMateria():" << std::endl;
    std::cout << "Learning Ice Materia..." << std::endl;
    src->learnMateria(new Ice());
    std::cout << "Learning Cure Materia..." << std::endl;
    src->learnMateria(new Cure());
    std::cout << "Learning another Ice Materia..." << std::endl;
    src->learnMateria(new Ice());
    std::cout << "Learning another Cure Materia..." << std::endl;
    src->learnMateria(new Cure());
    
    // Test learning too many Materias (should not crash, but should do nothing)
    std::cout << "\nTesting learning beyond capacity:" << std::endl;
    std::cout << "Attempting to learn a 5th Materia (should fail silently)..." << std::endl;
    src->learnMateria(new Ice()); // Should do nothing as inventory is full
    
    // Test creating Materias
    std::cout << "\nTesting createMateria():" << std::endl;
    
    // Create known Materias
    AMateria* ice = src->createMateria("ice");
    std::cout << "Created Materia type: " << ice->getType() << std::endl;
    
    AMateria* cure = src->createMateria("cure");
    std::cout << "Created Materia type: " << cure->getType() << std::endl;
    
    // Test creating an unknown Materia (should return NULL)
    std::cout << "\nAttempting to create unknown Materia type 'fire':" << std::endl;
    AMateria* unknown = src->createMateria("fire");
    if (unknown)
        std::cout << "ERROR: Should have returned NULL for unknown Materia type!" << std::endl;
    else
        std::cout << "Correctly returned NULL for unknown Materia type." << std::endl;
    
    // Clean up
    delete ice;
    delete cure;
    delete src;
}

void testCharacterEquipUnequip() {
    std::cout << "\n===== CHARACTER EQUIP/UNEQUIP TEST =====\n" << std::endl;
    
    // Create a MateriaSource and learn Materias
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // Create a Character
    std::cout << "Creating Character 'hero'..." << std::endl;
    Character* hero = new Character("hero");
    
    // Create Materias for equipping
    AMateria* materias[6]; // 6 Materias (more than the inventory can hold)
    std::cout << "\nCreating Materias for equipping:" << std::endl;
    for (int i = 0; i < 6; i++) {
        if (i % 2 == 0) {
            materias[i] = src->createMateria("ice");
            std::cout << "Created Ice Materia #" << i << std::endl;
        } else {
            materias[i] = src->createMateria("cure");
            std::cout << "Created Cure Materia #" << i << std::endl;
        }
    }
    
    // Test equipping Materias
    std::cout << "\nTesting equip():" << std::endl;
    std::cout << "Equipping 4 Materias (should all succeed)..." << std::endl;
    for (int i = 0; i < 4; i++) {
        hero->equip(materias[i]);
        std::cout << "Equipped " << materias[i]->getType() << " at slot " << i << std::endl;
    }
    
    // Test equipping when inventory is full
    std::cout << "\nAttempting to equip when inventory is full (should fail silently):" << std::endl;
    hero->equip(materias[4]);
    std::cout << "Equip attempt completed (should have done nothing)." << std::endl;
    
    // Test unequipping
    std::cout << "\nTesting unequip():" << std::endl;
    std::cout << "Unequipping slot 2..." << std::endl;
    hero->unequip(2);
    
    // Should be able to equip in the now-empty slot
    std::cout << "\nEquipping new Materia in the freed slot..." << std::endl;
    hero->equip(materias[4]);
    std::cout << "Equipped " << materias[4]->getType() << " in freed slot" << std::endl;
    
    // Test unequipping an invalid slot (should not crash)
    std::cout << "\nAttempting to unequip invalid slot 10 (should fail silently):" << std::endl;
    hero->unequip(10);
    std::cout << "Unequip attempt completed (should have done nothing)." << std::endl;
    
    // Need to save the unequipped Materia to delete it later
    AMateria* unequipped = materias[2];
    
    // Clean up (including the unequipped Materia)
    delete unequipped;
    delete materias[5]; // This one was never equipped
    delete hero;
    delete src;
}

void testCharacterCopy() {
    std::cout << "\n===== CHARACTER COPY TEST =====\n" << std::endl;
    
    // Create a MateriaSource and learn Materias
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // Create and equip original Character
    std::cout << "Creating and equipping original Character 'original'..." << std::endl;
    Character* original = new Character("original");
    
    AMateria* ice1 = src->createMateria("ice");
    AMateria* cure1 = src->createMateria("cure");
    original->equip(ice1);
    original->equip(cure1);
    
    // Test copy constructor
    std::cout << "\nTesting copy constructor:" << std::endl;
    Character* copy1 = new Character(*original);
    std::cout << "Copy created with name: " << copy1->getName() << std::endl;
    
    // Test assignment operator
    std::cout << "\nTesting assignment operator:" << std::endl;
    Character* copy2 = new Character("copy2");
    *copy2 = *original;
    std::cout << "Copy assigned with name: " << copy2->getName() << " (should still be 'copy2')" << std::endl;
    
    // Create a target for testing use()
    ICharacter* target = new Character("target");
    
    // Test using Materias from both copies
    std::cout << "\nTesting use() on original and copies:" << std::endl;
    std::cout << "Original using slot 0:" << std::endl;
    original->use(0, *target);
    std::cout << "Copy1 using slot 0:" << std::endl;
    copy1->use(0, *target);
    std::cout << "Copy2 using slot 1:" << std::endl;
    copy2->use(1, *target);
    
    // Modify original to prove deep copy
    std::cout << "\nModifying original to prove deep copy:" << std::endl;
    original->unequip(0);
    AMateria* newMateria = src->createMateria("cure");
    original->equip(newMateria);
    
    std::cout << "Original after modification (slot 0 should now be cure):" << std::endl;
    original->use(0, *target);
    std::cout << "Copy1 after original was modified (slot 0 should still be ice):" << std::endl;
    copy1->use(0, *target);
    
    // Clean up
    delete ice1; // We unequipped this one
    delete target;
    delete original;
    delete copy1;
    delete copy2;
    delete src;
}

void testMateriaUse() {
    std::cout << "\n===== MATERIA USE TEST =====\n" << std::endl;
    
    // Create Materias directly
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    
    // Create Characters
    ICharacter* cloud = new Character("Cloud");
    ICharacter* tifa = new Character("Tifa");
    
    // Test use() directly
    std::cout << "Testing use() on Ice Materia:" << std::endl;
    ice->use(*tifa);
    
    std::cout << "\nTesting use() on Cure Materia:" << std::endl;
    cure->use(*tifa);
    
    // Test cloning
    std::cout << "\nTesting clone() for Ice Materia:" << std::endl;
    AMateria* iceClone = ice->clone();
    std::cout << "Cloned Materia type: " << iceClone->getType() << std::endl;
    
    std::cout << "\nTesting clone() for Cure Materia:" << std::endl;
    AMateria* cureClone = cure->clone();
    std::cout << "Cloned Materia type: " << cureClone->getType() << std::endl;
    
    // Clean up
    delete ice;
    delete cure;
    delete iceClone;
    delete cureClone;
    delete cloud;
    delete tifa;
}

void testMemoryLeaks() {
    std::cout << "\n===== MEMORY LEAK TEST =====\n" << std::endl;
    std::cout << "This test ensures proper destruction of all objects." << std::endl;
    std::cout << "Check for memory leaks using valgrind or similar tools." << std::endl;
    
    // Create a complex scenario with multiple objects
    IMateriaSource* src = new MateriaSource();
    
    // Learn several Materias
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // Create multiple characters
    Character* hero = new Character("Hero");
    Character* ally = new Character("Ally");
    Character* enemy = new Character("Enemy");
    
    // Create and equip many Materias
    AMateria* materias[4];
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0)
            materias[i] = src->createMateria("ice");
        else
            materias[i] = src->createMateria("cure");
        hero->equip(materias[i]);
    }
    
    // Unequip a Materia (should not be deleted yet)
    hero->unequip(1);
    
    // Make a copy (deep copy should happen)
    Character* heroCopy = new Character(*hero);
    
    // Delete the original
    delete hero;
    
    // Use some Materias from the copy
    heroCopy->use(0, *enemy);
    heroCopy->use(2, *ally);
    
    // Clean up everything
    delete materias[1]; // The unequipped Materia
    delete heroCopy;
    delete ally;
    delete enemy;
    delete src;
    
    std::cout << "All objects destroyed. Check for memory leaks." << std::endl;
}

void testEdgeCases() {
    std::cout << "\n===== EDGE CASES TEST =====\n" << std::endl;
    
    // Create a MateriaSource and learn Materias
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // Create a Character
    Character* hero = new Character("Hero");
    
    // Test using an empty slot (should not crash)
    std::cout << "Testing use() on empty slot:" << std::endl;
    ICharacter* target = new Character("Target");
    hero->use(0, *target);
    std::cout << "No crash occurred (should have done nothing)." << std::endl;
    
    // Test unequipping an empty slot (should not crash)
    std::cout << "\nTesting unequip() on empty slot:" << std::endl;
    hero->unequip(0);
    std::cout << "No crash occurred (should have done nothing)." << std::endl;
    
    // Test equipping NULL (should not crash)
    std::cout << "\nTesting equip() with NULL:" << std::endl;
    hero->equip(NULL);
    std::cout << "No crash occurred (should have done nothing)." << std::endl;
    
    // Clean up
    delete hero;
    delete target;
    delete src;
}

int main() {
    std::cout << "========== COMPREHENSIVE TEST SUITE FOR EXERCISE 03 ==========\n" << std::endl;
    
    // Run all test cases
    testBasicFunctionality();
    testMateriaSource();
    testCharacterEquipUnequip();
    testCharacterCopy();
    testMateriaUse();
    testEdgeCases();
    testMemoryLeaks();
    
    std::cout << "\n========== ALL TESTS COMPLETED ==========\n" << std::endl;
    
    return 0;
}
