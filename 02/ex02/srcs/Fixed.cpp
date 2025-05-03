#include "Fixed.hpp"

/* Construct */

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int integer) : _value(integer << _fractionalBits) {}

Fixed::Fixed(const float floating) : _value(roundf(floating * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& other) : _value(other._value) {}

/* Detruct */

Fixed::~Fixed() {}

/* Arithmetic Operators */

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_value = other._value;
	return(*this);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (this->_value + other._value);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (this->_value - other._value);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed		multi;
	long long 	tmp;

	tmp = static_cast<long long>(this->_value) *
		 static_cast<long long>(other._value);
	multi._value = static_cast<int>(tmp >> Fixed::_fractionalBits);
	return (multi);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed		div;
	long long 	tmp;

	tmp = (static_cast<long long>(this->_value) << Fixed::_fractionalBits) /
			static_cast<long long>(other._value);
	div._value = static_cast<int>(tmp);
	return (div);
}

Fixed& Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++this->_value;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--this->_value;
	return (tmp);
}

/* Comparison Operators */

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_value != other._value);
}

/* Min Max things */

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a._value <= b._value)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a._value >= b._value)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._value <= b._value)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a._value >= b._value)
		return (a);
	return (b);
}

/* Methods */

int Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt() const
{
	return (this->_value >> Fixed::_fractionalBits);
}

float Fixed::toFloat() const
{
	return (static_cast<float>(this->_value) / (1 << Fixed::_fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

