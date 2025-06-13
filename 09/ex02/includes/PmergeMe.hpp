#pragma once

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <ctime>
#include <cmath>

#define RESET		"\033[0m"
#define YELLOW		"\033[33m"
#define BOLD		"\033[1m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define CYAN		"\033[36m"

typedef std::string string_t;
template <typename Container>
class PmergeMe {
public:
	typedef typename Container::iterator Iterator;

	PmergeMe() {}
	~PmergeMe() {}

	// Main sorting function
	static void mergeInsertionSort(Container& container) {
		if (container.size() <= 1) return;

		// Step 1: Sort pairs
		sortPairs(container);

		// Step 2: Extract and recursively sort larger elements
		Container larger;
		extractLargerElements(container, larger);
		mergeInsertionSort(larger);

		// Step 3: Merge and insert
		mergeAndInsert(container, larger);
	}

	void printContainer(Container container) {
		for (Iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

private:
	PmergeMe(const PmergeMe&); // c'est vrmnt super utile cette regle! 
	PmergeMe& operator=(const PmergeMe&);

	// --- Helper Functions ---

	// Step 1: Sort adjacent pairs (swap if [i] > [i+1])
	static void sortPairs(Container& container) {
		for (Iterator it = container.begin(); it != container.end(); ) {
			Iterator next = it;
			++next; // Manual replacement for std::next(it)
			if (next == container.end()) break; // Odd-sized case
			if (*it > *next) std::iter_swap(it, next);
			it = ++next; // Move to the next pair
		}
	}

	// Step 2: Extract larger elements from each pair
	static void extractLargerElements(Container& container, Container& larger) {
		for (Iterator it = container.begin(); it != container.end(); ) {
			Iterator next = it;
			++next; // Manual replacement for std::next(it)
			if (next == container.end()) {
				// Don't add the last odd element here - it will be handled in mergeAndInsert
				break;
			}
			larger.push_back(*next); // Larger element of the pair
			it = ++next; // Move to the next pair
		}
	}

	// Step 3: Merge sorted `larger` and insert remaining elements
	static void mergeAndInsert(Container& container, Container& larger) {
		Container sorted(larger.begin(), larger.end());
		for (Iterator it = container.begin(); it != container.end(); ) {
			Iterator next = it;
			++next; // p'tet que la promo de 2038 aura le droit au c++11!
			if (next == container.end()) {
				// Insert last odd element
				sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), *it), *it);
				break;
			}
			// Insert smaller element of the pair
			sorted.insert(std::lower_bound(sorted.begin(), sorted.end(), *it), *it);
			it = ++next; // Move to the next pair
		}
		container.swap(sorted); // Efficient copy
	}
};