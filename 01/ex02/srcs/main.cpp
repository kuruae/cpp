#include <iostream>

typedef std::string str;

int main()
{
	str string = "HI THIS IS BRAIN";
	str* stringPTR = &string;
	str& stringREF = string;

	// print adresses
	std::cout	<< "Adresses:\n"
				<< "string: " << &string << "\n"
				<< "pointer: " << stringPTR << "\n"
				<< "reference: " << &stringREF << "\n\n";

	// print values
	std::cout	<< "Values:\n"
				<< "string: " << string << "\n"
				<< "pointer: " << *stringPTR << "\n"
				<< "reference: " << stringREF << std::endl;
}