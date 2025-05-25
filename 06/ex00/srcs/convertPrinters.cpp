#include "ScalarConverter.hpp"

void printImpossible(const std::string& type)
{
	if (type == "all" || type == "char")
		std::cout << "char: impossible" << std::endl;
	
	if (type == "all" || type == "int")
		std::cout << "int: impossible" << std::endl;
	
	if (type == "all" || type == "float")
		std::cout << "float: impossible" << std::endl;
	
	if (type == "all" || type == "double")
		std::cout << "double: impossible" << std::endl;
}

void printSpecialCase(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		printImpossible("char");
		printImpossible("int");
		printFloat(std::numeric_limits<float>::quiet_NaN());
		printDouble(std::numeric_limits<double>::quiet_NaN());
	}
	else if (str == "-inf" || str == "-inff")
	{
		printImpossible("char");
		printImpossible("int");
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
	{
		printImpossible("char");
		printImpossible("int");
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str.empty())
		printImpossible();
	else
		std::cerr << "Unknown special case: " << str << std::endl;
}

void printCharLiteral(std::string str)
{
	char c = str[0];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void printFromDouble(const std::string& str)
{
	double d = atof(str.c_str());
	
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		printImpossible("char");
	else
		printChar(static_cast<char>(d));

	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		printImpossible("int");
	else
		printInt(static_cast<int>(d));

	if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
		printImpossible("float");
	else
		printFloat(static_cast<float>(d));
	
	printDouble(d);
}

/****** type printers *****/ 
void printDouble(double d)
{
	if (d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(15);
		std::cout << "double: " << d << std::endl;
	}
}

void printFloat(float f)
{
	if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(7);
		std::cout << "float: " << f << "f" << std::endl;
	}
}

void printInt(int i)
{
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void printChar(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}


