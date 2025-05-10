#include "setup.hpp"

int main(void)
{

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();

	wrong_animal->makeSound();
	k->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrong_animal;
	delete k;

	return (0);
}