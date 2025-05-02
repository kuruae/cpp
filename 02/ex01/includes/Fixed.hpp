#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int integer);
	Fixed(const float floating);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
	int		toInt() const;
	float	toFloat() const;
	
	private:
	const static int	_fractionalBits = 8;
	int					_value;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
