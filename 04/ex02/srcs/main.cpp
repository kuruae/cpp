#include "setup.hpp"

int main()
{
	Animal* animals[10];
	
	std::cout	<< " --- making 10 animal, which will be divided"
				<< " into 6 cats and 4 dogs ---" << std::endl;

	for (int i = 0; i < 6; i++)
		animals[i] = new Cat();

	for (int i = 6; i < 10; i++)
		animals[i] = new Dog();

	for (int i = 0; i < 10; i++)
	{
		std::cout 	<< "animal " << i << " is making this sound: ";
		animals[i]->makeSound();
		std::cout << std::endl;
	}

	Cat *initMiaou = dynamic_cast<Cat*>(animals[2]);
	if (initMiaou)
	{
		Cat* miaou = new Cat(*initMiaou);
		miaou->setIdea(3, "test");
		std::cout << "thinking about " << miaou->getIdea(3) << std::endl;
		
		std::cout << "\n\n///copying the cat and his evil ideas///\n\n" << std::endl;

		Cat* copy = new Cat(*miaou);
		std::cout << "thinking about " << copy->getIdea(3) << std::endl;

		delete miaou;
		delete copy;
	}
	else
		std::cout << "animals[2] is not a cat..." << std::endl;

	for (int i = 0; i < 10; i++)
		delete animals[i];

	return 0;
}