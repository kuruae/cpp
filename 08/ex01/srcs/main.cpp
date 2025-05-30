#include <iostream>
#include "Span.hpp"

#define RESET		"\033[0m"
#define YELLOW		"\033[33m"
#define BOLD		"\033[1m"
#define RED		"\033[31m"
#define GREEN		"\033[32m"
#define CYAN		"\033[36m"

int main()
{
std::cout << "==== SUBJECT'S TEST ====" << std::endl;
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;



std::cout <<	CYAN << "\n==== MY TEST ====\n\n" << 
			  	"==== testing the addNumbers method ====" << RESET << std::endl;

try{
	int arr[] = {14, 234, 100, 0, -3, 6, 77, 100000, -87, 10};

	std::cout << "Creating an array of ints then adding it to the Span object:" << std::endl;
	for (size_t i = 0; i < arraySize(arr); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	Span mySpan(15);
	mySpan.addNumbers(arr, arr + arraySize(arr));

	std::cout << "Added numbers successfully.\n" << std::endl;
	std::cout << "Shortest span: " << mySpan.shortestSpan() << "  (should be 3)" << std::endl;
	std::cout << "Longest span: " << mySpan.longestSpan() << "  (should be 100000 - (-87) = 100087)" << std::endl;

	std::cout << "\ntrying to append more numbers through iterators: " << std::endl;
	
	int arr2[] = {1, 2, 3, 4, 5};
	for (size_t i = 0; i < arraySize(arr); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	mySpan.addNumbers(arr2, arr2 + arraySize(arr2));
	std::cout << "\nAdded numbers successfully." << std::endl;

	std::cout << "\ntrying to add more numbers than the max size of the span:" << std::endl;
	mySpan.addNumber(2);

} catch (const std::exception& e) {
	std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
}



std::cout << CYAN "\n==== TESTING EDGE CASES ====" << RESET << std::endl;
try {
	std::cout << "Creating a Span with size 0 and trying to add a number:" << std::endl;
	Span emptySpan(0);
	emptySpan.addNumber(1);
} catch (const std::exception& e) {
	std::cerr << RED << "Exception: " << e.what() << RESET << std::endl << std::endl;
}
try {
	std::cout << "Creating a Span with one member then attempting to get the shortest span" << std::endl;
	Span singleElementSpan(1);
	singleElementSpan.addNumber(42);
	std::cout << "Single element span created successfully." << std::endl;
	std::cout << "Shortest span: " << singleElementSpan.shortestSpan() << std::endl; 
} catch (const std::exception& e) {
	std::cerr << RED << "Exception: " << e.what() << RESET << std::endl << std::endl;
}
try {
	std::cout << "Creating a Span with the two same members, then getting the shortest and longest span:" << std::endl;
	Span twoElementSpan(2);
	twoElementSpan.addNumber(2);
	twoElementSpan.addNumber(2);
	std::cout << "Shortest span: " << twoElementSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << twoElementSpan.longestSpan() << std::endl; 
} catch (const std::exception& e) {
	std::cerr << RED << "Exception: " << e.what() << RESET << std::endl << std::endl;
}



std::cout << CYAN "\n==== TESTING 20k members ====" << RESET << std::endl;
try {
	Span bigSpan(20000);
	for (int i = 0; i < 20000; ++i) {
		bigSpan.addNumber(i);
	}
	std::cout << "Added 20k numbers successfully." << std::endl;
	std::cout << "Shortest span: " << bigSpan.shortestSpan() << "  (should be 1)" << std::endl;
	std::cout << "Longest span: " << bigSpan.longestSpan() << "  (should be 19999)" << std::endl;
} catch (const std::exception& e) {
	std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
}

return 0;
}