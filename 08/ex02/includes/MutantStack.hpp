#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
	~MutantStack() {}

	MutantStack& operator=(const MutantStack& other)
	{
		if (this != &other)
			std::stack<T, Container>::operator=(other);
		return *this;
	}

	typedef typename std::stack<T, Container>::container_type::iterator iterator;

	iterator begin() {return this->c.begin(); }

	iterator end() {return this->c.end(); }
};