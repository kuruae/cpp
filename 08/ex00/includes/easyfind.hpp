#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T, size_t N>
size_t arraySize(T(&) [N])
{
	return N;
}

template <typename T>
int easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return *it;
	throw std::runtime_error("Value not found in the container");
}
