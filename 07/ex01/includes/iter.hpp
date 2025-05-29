#pragma once

#include <iostream>

/**
 * @brief Calculate the size of the array.
 * 
 * cool template function to calculate the size of an array
 * BUT the size must be known at compile time.
 */
template <typename T, size_t N>
size_t arraySize(T(&) [N])
{
	return N;
}

template <typename T>
void iter(T* array, size_t len, void (*func)(T&))
{
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}