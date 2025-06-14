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
	typedef typename Container::value_type value_type;

	PmergeMe() {}
	~PmergeMe() {}

	// Main sorting function - entry point
	void mergeInsertionSort(Container& container) {
		if (container.size() <= 1) return;
		mergeInsertionSortRecursive(container, 1);
	}

	void printContainer(Container& container)
	{
		for (Iterator it = container.begin(); it != container.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

private:
	PmergeMe(const PmergeMe& other) {(void)other; }
	PmergeMe& operator=(const PmergeMe& other) {
		(void)other;
		return *this;
	}

	// Recursive merge-insertion sort with order parameter
	void mergeInsertionSortRecursive(Container& vec, int order) {
		int unit = vec.size() / order;  // Number of groups of size 'order'
		if (unit < 2)
			return;
		
		bool hasOdd = (unit % 2 == 1);
		
		// Step 1: Compare and swap pairs of groups
		Iterator start = vec.begin();
		Iterator end = vec.begin() + ((order * unit) - (hasOdd * order));
		
		for (Iterator it = start; it < end; it += order * 2) {
			// Compare last elements of each group in the pair
			if (*(it + (order - 1)) > *(it + ((order * 2) - 1))) {
				// Swap the entire groups
				for (int i = 0; i < order; i++) {
					std::swap(*(it + i), *(it + i + order));
				}
			}
		}
		
		// Step 2: Recursively sort with double the order (pairs of groups)
		mergeInsertionSortRecursive(vec, order * 2);
		
		// Step 3: Separate into main chain, pending chain, and leftover
		Container main;
		Container pend;
		Container left;
		
		// First two groups go to main chain (they're already sorted)
		if (unit >= 2) {
			main.insert(main.end(), vec.begin(), vec.begin() + order);
			main.insert(main.end(), vec.begin() + order, vec.begin() + order * 2);
		}
		
		// Distribute remaining groups alternately
		int i = 2;
		while (i < unit) {
			if (i % 2 == 1) {
				// Odd index groups go to main chain (larger elements)
				main.insert(main.end(), vec.begin() + order * i, vec.begin() + (order * i) + order);
			} else {
				// Even index groups go to pending chain (smaller elements to be inserted)
				pend.insert(pend.end(), vec.begin() + order * i, vec.begin() + (order * i) + order);
			}
			i++;
		}
		
		// Handle leftover elements if any
		if (vec.size() > static_cast<size_t>(order * i)) {
			left.insert(left.end(), vec.begin() + order * i, vec.end());
		}
		
		// Step 4: Insert pending elements using Jacobsthal sequence
		binaryInsertion(main, pend, left, vec, order);
	}

	// Generate Jacobsthal sequence up to n
	void getJacobsthal(Container& jacob, size_t n) {
		if (jacob.empty()) {
			jacob.push_back(3);  // Start with 3 (first useful Jacobsthal number for insertion)
		}
		
		size_t prev = 1;
		while (static_cast<size_t>(jacob.back()) < n) {
			jacob.push_back(jacob.back() + 2 * prev);
			prev = *(jacob.end() - 2);
		}
	}

	// Insert a single group using binary search
	void insertionValue(Container& main, Container& pend, int idx, int order, int maxSearch) {
		int left = 1;
		int right = maxSearch;
		
		// Binary search for insertion position
		while (left <= right) {
			int mid = (left + right) / 2;
			// Compare last elements of groups (which represent the groups)
			if (main.at(mid * order - 1) == pend.at(idx * order - 1)) {
				left = mid;
				break;
			}
			else if (main.at(mid * order - 1) > pend.at(idx * order - 1)) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		
		// Insert the entire group at the found position
		main.insert(main.begin() + (left - 1) * order, 
					pend.begin() + idx * order - order, 
					pend.begin() + idx * order);
	}

	// Main insertion function using Jacobsthal sequence
	void binaryInsertion(Container& main, Container& pend, Container& left, Container& vec, int order) {
		size_t prev;
		Container jacob;
		size_t idx;
		
		// Generate Jacobsthal sequence
		jacob.push_back(3);
		getJacobsthal(jacob, pend.size() / order);
		
		if (!pend.empty()) {
			// Insert elements according to Jacobsthal sequence
			for (size_t i = 0; i < jacob.size(); i++) {
				prev = (jacob[i] == 3) ? 0 : jacob[i - 1] - 1;
				idx = jacob[i] - 1;
				
				// Don't exceed available elements
				if (idx > pend.size() / order) {
					idx = pend.size() / order;
				}
				
				// Insert elements in reverse order within Jacobsthal group
				while (idx > prev) {
					insertionValue(main, pend, idx, order, main.size() / order);
					idx--;
				}
			}
			
			// Insert any remaining elements after last Jacobsthal number
			if (static_cast<size_t>(*(jacob.end() - 1) - 1) < pend.size() / order) {
				int i = pend.size() / order;
				while (i > *(jacob.end() - 1) - 1) {
					insertionValue(main, pend, i, order, main.size() / order);
					i--;
				}
			}
		}
		
		// Copy sorted main chain back to original vector
		Iterator s = vec.begin();
		for (size_t i = 0; i < main.size(); i++) {
			*s = main.at(i);
			++s;
		}
		
		// Handle leftover elements
		if (left.size() == 1 && order == 1) {
			// Single leftover element - insert using binary search
			Iterator pos = std::lower_bound(vec.begin(), vec.begin() + main.size(), *left.begin());
			vec.insert(pos, *left.begin());
		} else if (!left.empty()) {
			// Multiple leftover elements - append them
			for (size_t i = 0; i < left.size(); i++) {
				*s = left.at(i);
				++s;
			}
		}
	}
};