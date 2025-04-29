#include "Harl.hpp"

int main()
{
	Harl harl;
	harl.complain("DEBUG");
	std::cout << "\n";
	harl.complain("INFO");
	std::cout << "\n";
	harl.complain("WARNING");
	std::cout << "\n";
	harl.complain("ERROR");
	std::cout << "\n";
	harl.complain("aaaaaaa");
	return (0);
}