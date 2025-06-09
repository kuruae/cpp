#include "BitcoinExchange.hpp"

double	convertToDoubleOrThrow(const string_t& str)
{
	char* endptr;
	double value = strtod(str.c_str(), &endptr);
	if (*endptr != '\0')
		throw std::runtime_error("Invalid number format");
	if (std::isnan(value))
		throw std::runtime_error("Not a number");
	return value;
}

bool	isLeapYear(int year)
{
	return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int	daysInMonth(Date date)
{
	static const int days[] = { 31, 28, 31, 30,
										31, 30, 31, 31,
										30, 31, 30, 31 };

	if (date.month == 2 && isLeapYear(date.year))
		return 29;

	else if (date.month < 1 || date.month > 12)
		return 0;

	else
		return days[date.month - 1];
}

string_t	trim(const string_t& str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	if (start == string_t::npos)
		throw std::runtime_error("String is empty after trimming");
	return (str.substr(start, end - start + 1));
}

size_t findSeparator(const string_t& line, char separator)
{
	size_t pos = line.find(separator);
	if (pos == string_t::npos)
		throw std::runtime_error("Invalid line format");
	return pos;
}