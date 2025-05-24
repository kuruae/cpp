#include "ScalarConverter.hpp"

/* useless constructors ***********************************************************/
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}
/*********************************************************************************/


void ScalarConverter::convert(const std::string& str)
{
	if (isSpecialCase(str))
		printSpecialCase(str);

	else if (isCharLiteral(str))
		printCharLiteral(str);

	else if (str.find_first_not_of("0123456789+-.f") != std::string::npos)
		printImpossible();

	else if (looksLikeDouble(str))
		printFromDouble(str);

	else
		printImpossible();
}