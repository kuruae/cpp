#include "PmergeMe.hpp"
#include <cstdlib>

static void	checkNumber(std::string nb)
{
	if (nb.empty())
		throw std::invalid_argument("Input cannot be empty");
	
	for (size_t i = 0; i < nb.size(); i++)
	{
		if (!isdigit(nb[i]))
			throw std::invalid_argument("Invalid character in input: " + nb);
	}

	long value = std::atol(nb.c_str());
	if (value > std::numeric_limits<int>::max() || value < 0)
		throw std::out_of_range("Number out of range: " + nb);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr	<< RED << "Error: No arguments provided.\n"
					<< "Usage: " << argv[0]
					<< " <positive integer 1> <positive integer 2> ... <positive integer n>"
					<< RESET << std::endl;
		return 1;
	}

	try
	{
		PmergeMe<std::vector<int> >	vecMegre;
		PmergeMe<std::deque<int> >	deqMegre;
		std::vector<int>			vec;
		std::deque<int>				deq;

		for (int i = 1; i < argc; ++i)
		{
			checkNumber(argv[i]);
			int num = std::atoi(argv[i]);
			vec.push_back(num);
			deq.push_back(num);
		}

		std::cout << "running Ford Johnson algorithm using a vector...\nbefore: ";
		vecMegre.printContainer(vec);

		clock_t startClock = clock();

		vecMegre.mergeInsertionSort(vec);
		
		clock_t endClock = clock();
		double vecElapsedTime = static_cast<double>(endClock - startClock) / CLOCKS_PER_SEC * 1000000;

		std::cout << "after:  ";
		vecMegre.printContainer(vec);


		std::cout << "\n\nrunning Ford Johnson algorithm using a deque...\nbefore: ";
		deqMegre.printContainer(deq);

		startClock = clock();

		deqMegre.mergeInsertionSort(deq);

		endClock = clock();
		double deqElapsedTime = static_cast<double>(endClock - startClock) / CLOCKS_PER_SEC * 1000000;

		std::cout << "after:  ";
		deqMegre.printContainer(deq);

		// 1 microsecond = 1/1 000 000 seconds (= 0.000001 seconds)
		std::cout << "\n\nTime to process " << vec.size() << " elements with a vector: "
				  << vecElapsedTime << " microseconds" << std::endl;

		std::cout << "Time to process " << deq.size() << " elements with a deque: "
				  << deqElapsedTime << " microseconds" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << RESET << e.what() << std::endl;
		return (1);
	}

	return (0);
}