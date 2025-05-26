#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {(void)other;}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
	if (!ptr)
		throw std::invalid_argument("Null pointer cannot be serialized");
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	if (raw == 0)
		throw NullPointerException();
	return reinterpret_cast<Data*>(raw);
}

Serializer::NullPointerException::NullPointerException() :
std::runtime_error("Null pointer exception") {}