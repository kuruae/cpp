#include <iostream>
#include "easyfind.hpp"

int main()
{
	try
	{
		int arr[] = {1, 2, 3, 4, 5};
		std::vector<int> vec(arr, arr + arraySize(arr));
		int valueToFind = 3;

		std::vector<int>::iterator foundValue = easyfind(vec, valueToFind);
		std::cout << "Found value: " << *foundValue << std::endl;

		valueToFind = 6;
		foundValue = easyfind(vec, valueToFind);
		std::cout << "Found value: " << *foundValue << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}