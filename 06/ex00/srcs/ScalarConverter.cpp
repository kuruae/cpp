#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

static void printImpossible(const std::string& type = "all")
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


static void printChar(char c)
{
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void printInt(int i)
{
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

static void printFloat(float f)
{
	if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(7);
		std::cout << "float: " << f << "f" << std::endl;
	}
}

static void printDouble(double d)
{
	if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(15);
		std::cout << "double: " << d << std::endl;
	}
}

static bool isCharLiteral(const std::string& str)
{
	if (str.length() == 1 && std::isprint(str[0]))
	{
		if ((str.find_first_not_of("0123456789") != std::string::npos))
			return true;
	}
	return false;
}

static void printCharLiteral(std::string str)
{
	char c = str[0];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

static bool looksLikeDouble(const std::string& str)
{
	char* endptr;
	strtod(str.c_str(), &endptr);
	return (*endptr == '\0' || *endptr == 'f');
}

static void convertFromDouble(const std::string& str)
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

	if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
		printImpossible("float");
	else
		printFloat(static_cast<float>(d));
	
	printDouble(d);
}

static void printSpecialCase(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
	if (str == "nan" || str == "-inf" || str == "+inf")
		printSpecialCase(str);

	else if (isCharLiteral(str))
		printCharLiteral(str);

	else if (str.find_first_not_of("0123456789+-.f") != std::string::npos)
		printImpossible();

	else if (looksLikeDouble(str))
		convertFromDouble(str);

	else
		printImpossible();
}