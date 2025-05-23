#include "ScalarConverter.hpp"

// int main()
// {
// 	std::cout << "===== PRINTING REAL std::numeric_limits BEHAVIOR =====" << std::endl;
// 	std::cout << "float -inf: " << -std::numeric_limits<float>::infinity() << std::endl;
//     std::cout << "double +inf: " << std::numeric_limits<double>::infinity() << std::endl;
//     std::cout << "float NaN: " << std::numeric_limits<float>::quiet_NaN() << std::endl;
//     std::cout << "double NaN: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
// 	std::cout << "int -inf: " << -std::numeric_limits<int>::infinity() << std::endl;
// 	std::cout << "int +inf: " << std::numeric_limits<int>::infinity() << std::endl;
// 	std::cout << "char -inf: " << -std::numeric_limits<char>::infinity() << std::endl;
// 	std::cout << "char +inf: " << std::numeric_limits<char>::infinity() << "\n\n" << std::endl;
// 	std::cout << "===== TESTING SCALAR CONVERTER WITH SPECIAL CASES =====" << std::endl;
// 	ScalarConverter::convert("nanf");
// 	ScalarConverter::convert("-inf");
// 	ScalarConverter::convert("-inff");
// 	ScalarConverter::convert("+inf");
// 	ScalarConverter::convert("+inff");
// 	std::cout << "\n'\n" << std::endl;
// 	std::cout << "===== TESTING SCALAR CONVERTER WITH NORMAL CASES =====" << std::endl;
// 	char c = 19;
// 	std::cout << "test: " << static_cast<>(c) << std::endl;
// 	// ScalarConverter::convert("42.0");
// 	// ScalarConverter::convert("42.0f");
// 	// ScalarConverter::convert("42");
// 	// ScalarConverter::convert("a");
// 	return 0;
	
// }

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./ScalarConverter <value>" << std::endl;
		return 1;
	}
	
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}	