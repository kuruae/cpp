#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <stdlib.h>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();

	ScalarConverter& operator=(const ScalarConverter& other);

	static void convert(const std::string& str);
private:

};