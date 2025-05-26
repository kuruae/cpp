#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <stdlib.h>

class ScalarConverter
{
public:
	static void convert(const std::string& str);
	
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);

};

// printers
	void	printImpossible(const std::string& type = "all");
	void	printSpecialCase(const std::string& str);
	
	void	printCharLiteral(std::string str);
	void	printFromDouble(const std::string& str);
	
	void	printDouble(double d);
	void	printFloat(float f);
	void	printInt(int i);
	void	printChar(char c);

//utils
	bool	isSpecialCase(const std::string& str);
	bool	isCharLiteral(const std::string& str);
	bool	looksLikeDouble(const std::string& str);