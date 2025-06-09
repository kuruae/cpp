#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr	<< RED << "Error: Incorrect number of arguments.\n"
					<< "Usage: " << argv[0]
					<< "\"<reverse polish mathematical expression>\""
					<< RESET << std::endl;
		return 1;
	}

	try
	{
		RPN rpn;
		rpn.run(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED"Fatal error: "RESET << e.what() << std::endl;
		return (1);
	}

	return (0);
}