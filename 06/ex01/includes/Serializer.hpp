#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

typedef struct Data
{
	int		value;
	int		otherValue;
} Data;

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	virtual ~Serializer();

private:
	Serializer(); // Prevent instantiation
	Serializer(const Serializer& other); // Prevent copying
	Serializer& operator=(const Serializer& other); // Prevent assignment
};