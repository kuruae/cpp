#include "ScalarConverter.hpp"

bool isSpecialCase(const std::string& str)
{
	return (str == "nan" || str == "-inf" || str == "+inf" ||
			str == "-inff" || str == "+inff" || str == "nanf" ||
			str == "inf" || str == "inff");
} 

bool isCharLiteral(const std::string& str)
{
	if (str.length() == 1 && std::isprint(str[0]))
	{
		if ((str.find_first_not_of("0123456789") != std::string::npos))
			return true;
	}
	return false;
}

bool looksLikeDouble(const std::string& str)
{
	char* endptr;
	strtod(str.c_str(), &endptr);
	return (*endptr == '\0' || *endptr == 'f');
}
