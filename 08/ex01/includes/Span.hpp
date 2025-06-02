#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <exception>
#include <limits>


template <typename T, size_t N>
size_t arraySize(T(&) [N])
{
	return N;
}


class Span
{
public:
	Span();
	Span(unsigned int maxsize);
	Span(const Span& other);
	~Span();

	Span&	operator=(const Span& other);

	void	addNumber(int N);
	
	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		if (std::distance(begin, end) + _vector.size() > _maxsize)
			throw std::length_error("Adding these numbers exceeds the maximum size of the span");
		_vector.insert(_vector.end(), begin, end);
	}

	int		shortestSpan() const;
	int		longestSpan() const;


private:
	unsigned int			_maxsize;
	std::vector<int>	_vector;

};