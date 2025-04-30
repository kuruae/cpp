#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);

private:
	int					_value;
	const static int	_fractionalBits = 8;
};