#include <ctime>
#include <cstdlib>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


#define RESET		"\033[0m"
#define YELLOW		"\033[33m"
#define BOLD		"\033[1m"

Base*	generate(void)
{
	std::srand(static_cast<unsigned int>(time(NULL)));
	int		randNum = std::rand() % 3;

	switch (randNum)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		default:
			return (new C);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << YELLOW BOLD << "A" << RESET << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << YELLOW BOLD << "B" << RESET << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << YELLOW BOLD << "C" << RESET << std::endl;
	}
	else
	{
		std::cout << "Unknown type" << std::endl;
	}
}

void	identify(Base& p)
{
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << YELLOW BOLD << "A" << RESET << std::endl;
	}
	catch (...) {}
	
	try{
		(void)dynamic_cast<B&>(p);
		std::cout << YELLOW BOLD << "B" << RESET << std::endl;
	}
	catch (...) {}

	try{
		(void)dynamic_cast<C&>(p);
		std::cout << YELLOW BOLD << "C" << RESET << std::endl;
	}
	catch (...) {}
}

int	main(void)
{
	Base *basePtr = generate();

	std::cout << "\nIdentify by pointer:" RESET << std::endl;

	identify(basePtr);

	std::cout << "\nIdentify by reference:" RESET << std::endl;

	identify(*basePtr);
	
	delete basePtr;

	return (0);
}