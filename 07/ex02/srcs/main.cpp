#include <iostream>
#include "Array.hpp"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
//

int main()
{
	try
	{
		Array<double> doubleArray(5);
		for (size_t i = 0; i < doubleArray.size(); ++i)
			doubleArray[i] = M_PI * i;

		std::cout << "Double Array: ";
		for (size_t i = 0; i < doubleArray.size(); ++i)
			std::cout << doubleArray[i] << " ";
		std::cout << std::endl;

		Array<std::string> strArray(3);
		strArray[0] = "Hello";
		strArray[1] = "World";
		strArray[2] = "!";

		std::cout << "String Array: ";
		for (size_t i = 0; i < strArray.size(); ++i)
			std::cout << strArray[i] << " ";
		std::cout << std::endl;

		std::cout << "Accessing out of bounds index: ";
		std::cout << doubleArray[10] << std::endl;
	}
	catch (const Array<double>::OutOfBoundsException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}