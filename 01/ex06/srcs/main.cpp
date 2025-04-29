#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || (std::string(argv[1]).empty()))
	{
		std::cerr << "Incorrect arguments" << std::endl;
		return (1);
	}

	Harl().complain(std::string(argv[1]));
	return (0);
}