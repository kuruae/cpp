#include "ScalarConverter.hpp"

ScalarConverter u;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./ScalarConverter <value>" << std::endl;
		return 1;
	}
	
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}	