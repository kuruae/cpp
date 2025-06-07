#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr	<< RED << "Error: Incorrect number of arguments.\n"
					<< "Usage: " << argv[0] << " <filename>" << RESET << std::endl;
		return 1;
	}


	try
	{
		BitcoinExchange exchange;
		
		exchange.runFile(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "Fatal error: " << e.what() << RESET << std::endl;
	}

	return 0;
}