#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr	<< RED << "Error: Incorrect number of arguments.\n"
					<< "Usage: " << argv[0]
					<< "\"<sequence of integers>\""
					<< RESET << std::endl;
		return 1;
	}

	try
	{
		// PmergeMe pmergeMe;
		// PmergeMe pmergeMe(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED"Error: "RESET << e.what() << std::endl;
		return (1);
	}

	return (0);
}