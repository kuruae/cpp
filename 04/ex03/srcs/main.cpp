#include "setup.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// main example test from the subject 
void testBasicFunctionality() {
	std::cout << "\n===== SUBJECT EXAMPLE =====\n" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
}


void testMateriaSource() {
	std::cout << "\n===== MATERIA SOURCE TEST =====\n" << std::endl;
	
	IMateriaSource* src = new MateriaSource();

	std::cout << "\nTesting learnMateria():" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << "\nTesting learning beyond capacity:" << std::endl;
	src->learnMateria(new Ice()); //<--- Should do nothing bc inventory is full
	
	// Create a Character to hold materias
	Character* cloud = new Character("Cloud");
	
	std::cout << "\nTesting createMateria():" << std::endl;

	// Create known Materias
	AMateria* ice = src->createMateria("ice");
	cloud->equip(ice);
	std::cout << "Created Materia type: " << ice->getType() << std::endl;
	
	AMateria* cure = src->createMateria("cure");
	cloud->equip(cure);
	std::cout << "Created Materia type: " << cure->getType() << std::endl;
	
	// Test creating an unknown Materia
	std::cout << "\nAttempting to create unknown Materia type 'fire':" << std::endl;
	AMateria* unknown = src->createMateria("fire");
	if (unknown)
		std::cout << "ERROR: Returned non-NULL for unknown Materia type!" << std::endl;
	else
		std::cout << "Correctly returned NULL for unknown Materia type." << std::endl;

	delete cloud;
	delete src;
}

void testCharacterFunctionality() {
	std::cout << "\n===== CHARACTER FUNCTIONALITY TEST =====\n" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << "Creating Character 'sephiroth'" << std::endl;
	Character* sephiroth = new Character("sephiroth");

	std::cout << "\nTesting equip():" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0)
		{
			sephiroth->equip(src->createMateria("ice"));
			std::cout << "Equipped ice at slot " << i << std::endl;
		}
		else
		{
			sephiroth->equip(src->createMateria("cure"));
			std::cout << "Equipped cure at slot " << i << std::endl;
		}
	}
	
	std::cout << "\nAttempting to equip when inventory is full:" << std::endl;
	AMateria* extra = src->createMateria("ice");
	sephiroth->equip(extra);

	std::cout << "\nTesting unequip():" << std::endl;
	sephiroth->unequip(2);
	
	std::cout << "\nEquipping new Materia in the freed slot..." << std::endl;
	sephiroth->equip(src->createMateria("ice"));
	
	// Copy constructor test
	std::cout << "\nTesting copy constructor:" << std::endl;
	Character* copy1 = new Character(*sephiroth);
	std::cout << "Copy created with name: " << copy1->getName() << std::endl;
	
	// Assignment operator test
	std::cout << "\nTesting assignment operator:" << std::endl;
	Character* copy2 = new Character("copy2");
	*copy2 = *sephiroth;
	std::cout << "Copy assigned with name: " << copy2->getName() << " (should still be 'copy2')" << std::endl;
	
	// target for testing use()
	ICharacter* target = new Character("target");
	
	std::cout << "\nTesting use() on original and copies:" << std::endl;
	sephiroth->use(0, *target);
	copy1->use(0, *target);
	
	// modify original to prove deep copy
	std::cout << "\nModifying original to prove deep copy:" << std::endl;
	sephiroth->unequip(0);
	sephiroth->equip(src->createMateria("cure"));
	
	sephiroth->use(0, *target);
	copy1->use(0, *target); //<--- Should still be ice
	
	delete target;
	delete sephiroth;
	delete copy1;
	delete copy2;
	delete src;
}

// Floor = unequipped materias or out of inventory space
void testFloorManagement() {
	std::cout << "\n===== FLOOR MANAGEMENT TEST =====\n" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	Character* tifa = new Character("tifa");
	
	for (int i = 0; i < 4; i++) {
		tifa->equip(src->createMateria(i % 2 == 0 ? "ice" : "cure"));
	}
	std::cout << "Filled inventory with 4 Materias" << std::endl;
	
	std::cout << "\nUnequipping multiple Materias:" << std::endl;
	tifa->unequip(0);
	tifa->unequip(2);
	tifa->unequip(3);
	std::cout << "Unequipped Materias at slots 0, 2, and 3" << std::endl;
	

	std::cout << "\nRe-equipping in empty slots:" << std::endl;
	tifa->equip(src->createMateria("ice"));
	tifa->equip(src->createMateria("cure"));
	std::cout << "Re-equipped Materias in slots 0 and 2" << std::endl;
	
	// Create a target and test use
	ICharacter* target = new Character("Target");
	tifa->use(0, *target);
	tifa->use(1, *target);
	tifa->use(2, *target);
	
	// Test that unequipped materias are properly tracked
	std::cout << "\nUnequipping all Materias to ensure proper cleanup:" << std::endl;
	for (int i = 0; i < 4; i++) {
		tifa->unequip(i);
	}

	// Destructor should handle all Materias (equipped and on floor)
	std::cout << "\nDestroying Character (should clean up all Materias)..." << std::endl;
	delete tifa;
	delete target;
	delete src;
}

// Edge cases de con
void testEdgeCases() {
	std::cout << "\n===== ENHANCED EDGE CASES TEST =====\n" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	
//--------------------------------------------------------------
	std::cout << "Test Case 1: Multiple unequips on the same slot" << std::endl;
	Character* hero = new Character("Hero");
	hero->equip(src->createMateria("ice"));
	
	std::cout << "First unequip (should work):" << std::endl;
	hero->unequip(0);
	
	std::cout << "Second unequip on same slot (should do nothing):" << std::endl;
	hero->unequip(0);


//--------------------------------------------------------------
	std::cout << "\nTest Case 2: Out of bounds" << std::endl;
	std::cout << "Using slot -1 (should handle safely / do nothing)..." << std::endl;
	ICharacter* target = new Character("Target");
	hero->use(-1, *target);
	
	std::cout << "Using slot 10 (should handle safely / do nothing)..." << std::endl;
	hero->use(10, *target);


//--------------------------------------------------------------
	std::cout << "\nTest Case 3: NULL handling" << std::endl;

	std::cout << "Equipping NULL materia (should handle safely / do nothing)..." << std::endl;
	hero->equip(NULL);


//--------------------------------------------------------------
	delete hero;
	delete target;
	delete src;
}


void testMateriaCloning() {
	std::cout << "\n===== MATERIA CLONING TEST =====\n" << std::endl;
	
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	
	std::cout << "Cloning Ice materia:" << std::endl;
	AMateria* iceClone = ice->clone();
	std::cout   << "Original type: " << ice->getType() 
				<< ", Clone type: " << iceClone->getType() << std::endl;
	
	std::cout << "\nCloning Cure materia:" << std::endl;
	AMateria* cureClone = cure->clone();
	std::cout   << "Original type: " << cure->getType()
				<< ", Clone type: " << cureClone->getType() << std::endl;
	
	ICharacter* target = new Character("Target");
	
	std::cout << "\nUsing original Ice:" << std::endl;
	ice->use(*target);
	std::cout << "Using cloned Ice:" << std::endl;
	iceClone->use(*target);
	
	// Clean up
	delete ice;
	delete cure;
	delete iceClone;
	delete cureClone;
	delete target;
}

int main()
{
	std::cout << "========== RUNNING TEST SUITE ==========\n" << std::endl;

	testBasicFunctionality();   // subject test
	testMateriaSource();
	testCharacterFunctionality();
	testFloorManagement();
	testMateriaCloning();
	testEdgeCases();

	std::cout << "\n========== ALL TESTS COMPLETED ==========\n" << std::endl;
	
	return 0;
}
