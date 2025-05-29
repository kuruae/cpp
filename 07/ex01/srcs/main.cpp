#include <iostream>
#include "iter.hpp"

void	testPrint(int& n)
{
	std::cout << n << " ";
}

void	testPrint(std::string& str)
{
	std::cout << str << " ";
}

int main()
{
	int intArr[] = {1, 2, 3, 4, 5};
	std::string strArr[] = {"testing", "iter", "function", "with", "strings"};

	std::cout << "Testing with integers: ";
	iter(intArr, arraySize(intArr), testPrint);

	std::cout << std::endl;
	
	std::cout << "Testing with strings: ";
	iter(strArr, arraySize(strArr), testPrint);

	std::cout << std::endl;
	return 0;
}
