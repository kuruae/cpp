#include "setup.hpp"

int main()
{
	const Animal* j = new Dog();
	std::cout << std::endl;

	const Animal* i = new Cat();
	std::cout << std::endl;

	i->readBrain();
	std::cout << std::endl;
	std::cout << std::endl;

	delete j;
	std::cout << std::endl;

	delete i;
	std::cout << std::endl;

	return 0;
}