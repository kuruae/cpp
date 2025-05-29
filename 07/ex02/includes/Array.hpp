#pragma once

#include <iostream>

template <typename T>
class Array
{
public:
	Array() : _size(0), _array(NULL) {}

	Array(size_t size) : _size(size), _array(new T[size]()) {}

	Array(const Array& other) : _size(other._size), _array(new T[other._size])
	{
		for (size_t i = 0; i < _size; ++i)
			_array[i] = other._array[i];
	}

	~Array() { delete[] _array; }

	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] _array;
			_size = other._size;
			_array = new T[_size];
			for (size_t i = 0; i < _size; ++i)
				_array[i] = other._array[i];
		}
		return *this;
	}

	size_t size() const { return _size; }

	T& operator[](size_t index)
	{
		if (index >= _size)
			throw OutOfBoundsException();
		return _array[index];
	}

	const T& operator[](size_t index) const
	{
		if (index >= _size)
			throw OutOfBoundsException();
		return _array[index];
	}

	class OutOfBoundsException : public std::runtime_error
	{
	public:
		OutOfBoundsException() : std::runtime_error("Index out of bounds") {}
	};

private:
	size_t	_size;
	T*		_array;
};