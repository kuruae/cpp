#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <stdint.h>

typedef struct Data
{
	std::string	name;
	int			value;
} Data;

class Serializer
{
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

	class NullPointerException : std::runtime_error
	{
	public:
		NullPointerException();
	};

private:
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();
};