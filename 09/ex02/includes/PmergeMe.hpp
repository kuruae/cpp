#pragma once

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <ctime>
#include <cmath>

#define RESET       "\033[0m"
#define YELLOW      "\033[33m"
#define BOLD        "\033[1m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define CYAN        "\033[36m"

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
		if (container.size() <= 1)
			return;
		sortWithMergeInsertion(container, 1);
	}

	void printContainer(Container& container) {
		for (Iterator it = container.begin(); it != container.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

private:
	PmergeMe(const PmergeMe& other) { (void)other; }
	PmergeMe& operator=(const PmergeMe& other)
	{
		(void)other;
		return *this;
	}

	struct SortChains
	{
		Container mainChain;
		Container pendingElements;
		Container leftoverElements;
	};


	
	// Recursive merge-insertion sort with specified group size
	void sortWithMergeInsertion(Container& container, int groupSize) {
		int groupCount = container.size() / groupSize;
		if (groupCount < 2)
			return;
		
		bool hasOddNumberOfGroups = (groupCount % 2 == 1);
		Iterator startPos = container.begin();
		Iterator endPos = container.begin() + ((groupSize * groupCount) - (hasOddNumberOfGroups * groupSize));
		
		// Step 1: Compare and swap pairs of groups
		comparePairsAndSwap(startPos, endPos, groupSize);
		
		// Step 2: Recursively sort with double the group size
		sortWithMergeInsertion(container, groupSize * 2);
		
		// Step 3: Split into main chain and pending elements using our new struct
		SortChains chains;
		distributeElements(container, chains, groupSize, groupCount);
		
		// Step 4: Insert pending elements using binary search guided by Jacobsthal sequence
		insertPendingElements(chains, container, groupSize);
	}

	// Compare and swap adjacent group pairs if needed
	void comparePairsAndSwap(Iterator start, Iterator end, int groupSize) {
		for (Iterator it = start; it < end; it += groupSize * 2) {
			// Compare last elements of each group in the pair
			if (*(it + (groupSize - 1)) > *(it + ((groupSize * 2) - 1))) {
				// Swap entire groups
				for (int i = 0; i < groupSize; i++) {
					std::swap(*(it + i), *(it + i + groupSize));
				}
			}
		}
	}

	// Distribute elements into main chain, pending elements, and leftover
	void distributeElements(Container& source, SortChains& chains, int groupSize, int groupCount) {
		// First two groups go to main chain (they're already sorted)
		if (groupCount >= 2) {
			chains.mainChain.insert(chains.mainChain.end(), source.begin(), source.begin() + groupSize * 2);
		}
		
		// Distribute remaining groups alternately
		for (int i = 2; i < groupCount; i++) {
			Iterator groupStart = source.begin() + groupSize * i;
			Iterator groupEnd = groupStart + groupSize;
			
			if (i % 2 == 1) {
				// Odd index groups go to main chain (larger elements)
				chains.mainChain.insert(chains.mainChain.end(), groupStart, groupEnd);
			} else {
				// Even index groups go to pending elements (smaller elements to be inserted)
				chains.pendingElements.insert(chains.pendingElements.end(), groupStart, groupEnd);
			}
		}
		
		// Handle leftover elements if any
		if (source.size() > static_cast<size_t>(groupSize * groupCount)) {
			chains.leftoverElements.insert(chains.leftoverElements.end(), 
								   source.begin() + groupSize * groupCount, 
								   source.end());
		}
	}

	// Generate Jacobsthal sequence up to n
	void generateJacobsthalSequence(Container& sequence, size_t upperLimit) {
		if (sequence.empty()) {
			sequence.push_back(3);  // Start with 3 (first useful number for insertion)
		}
		
		size_t prevValue = 1;
		while (static_cast<size_t>(sequence.back()) < upperLimit) {
			sequence.push_back(sequence.back() + 2 * prevValue);
			prevValue = *(sequence.end() - 2);
		}
	}

	// Insert a group using binary search
	void insertGroupWithBinarySearch(Container& mainChain, Container& pendingElements, 
									int groupIdx, int groupSize, int searchLimit) {
		int left = 1;
		int right = searchLimit;
		
		// Binary search for insertion position
		while (left <= right) {
			int mid = (left + right) / 2;
			if (mainChain.at(mid * groupSize - 1) == pendingElements.at(groupIdx * groupSize - 1)) {
				left = mid;
				break;
			}
			else if (mainChain.at(mid * groupSize - 1) > pendingElements.at(groupIdx * groupSize - 1)) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		
		// Insert the entire group at the found position
		mainChain.insert(mainChain.begin() + (left - 1) * groupSize, 
						pendingElements.begin() + groupIdx * groupSize - groupSize, 
						pendingElements.begin() + groupIdx * groupSize);
	}

	// Insert pending elements using Jacobsthal sequence
	void insertPendingElements(SortChains& chains, Container& originalContainer, int groupSize) {
		Container jacobsthalSeq;
		jacobsthalSeq.push_back(3);
		generateJacobsthalSequence(jacobsthalSeq, chains.pendingElements.size() / groupSize);
		
		if (!chains.pendingElements.empty()) {
			// Insert elements according to Jacobsthal sequence
			insertElementsFollowingJacobsthal(chains.mainChain, chains.pendingElements, jacobsthalSeq, groupSize);
		}
		
		// Copy sorted main chain back to original container
		copyMainChainToOriginal(chains, originalContainer, groupSize);
	}
	
	// Insert elements following Jacobsthal sequence
	void insertElementsFollowingJacobsthal(Container& mainChain, Container& pendingElements, 
										 Container& jacobsthalSeq, int groupSize) {
		size_t pendingGroupCount = pendingElements.size() / groupSize;
		
		// Process each Jacobsthal range
		for (size_t i = 0; i < jacobsthalSeq.size(); i++) {
			size_t prevIdx = (jacobsthalSeq[i] == 3) ? 0 : jacobsthalSeq[i - 1] - 1;
			size_t currIdx = jacobsthalSeq[i] - 1;
			
			// Don't exceed available elements
			if (currIdx > pendingGroupCount) {
				currIdx = pendingGroupCount;
			}
			
			// Insert elements in reverse order within Jacobsthal range
			while (currIdx > prevIdx) {
				insertGroupWithBinarySearch(mainChain, pendingElements, currIdx, 
										   groupSize, mainChain.size() / groupSize);
				currIdx--;
			}
		}
		
		// Insert any remaining elements after last Jacobsthal number
		size_t lastJacobsthalValue = jacobsthalSeq.back() - 1;
		if (lastJacobsthalValue < pendingGroupCount) {
			for (size_t i = pendingGroupCount; i > lastJacobsthalValue; i--) {
				insertGroupWithBinarySearch(mainChain, pendingElements, i, 
										  groupSize, mainChain.size() / groupSize);
			}
		}
	}
	
	// Copy main chain back to original container and handle leftovers
	void copyMainChainToOriginal(SortChains& chains, Container& originalContainer, int groupSize) {
		// Copy sorted main chain
		Iterator destIt = originalContainer.begin();
		for (size_t i = 0; i < chains.mainChain.size(); i++) {
			*destIt = chains.mainChain.at(i);
			++destIt;
		}
		
		// Handle leftover elements
		if (chains.leftoverElements.size() == 1 && groupSize == 1) {
			// Single leftover element - insert using binary search
			Iterator pos = std::lower_bound(originalContainer.begin(), 
										  originalContainer.begin() + chains.mainChain.size(), 
										  *chains.leftoverElements.begin());
			originalContainer.insert(pos, *chains.leftoverElements.begin());
		} else if (!chains.leftoverElements.empty()) {
			// Multiple leftover elements - append them
			for (size_t i = 0; i < chains.leftoverElements.size(); i++) {
				*destIt = chains.leftoverElements.at(i);
				++destIt;
			}
		}
	}
};