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
	~Fixed();

	// arithmetic op
	Fixed& operator=(const Fixed& other);
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	//pre
	Fixed& operator++(void);
	Fixed& operator--(void);
	//post
	Fixed operator++(int);
	Fixed operator--(int);

	// comparison op
	bool operator==(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// min max
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
	int		toInt() const;
	float	toFloat() const;
	
	private:
	const static int	_fractionalBits = 8;
	int					_value;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
