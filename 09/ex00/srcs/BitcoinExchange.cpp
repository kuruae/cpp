#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){(void)other;}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		(void)other;
	return *this;
}

void	BitcoinExchange::parseDate(const string_t& line)
{
	size_t pos = line.find('|');
	if (pos == string_t::npos)
		std::cerr << RED << "Error: Invalid line format, missing '|': " << line << RESET << std::endl;

	string_t dateStr = line.substr(0, pos);
	string_t valueStr = line.substr(pos + 1);

	// parse date
	int matches = std::sscanf(dateStr.c_str(), "%d-%d-%d"
					, &_date.year, &_date.month, &_date.day);
	if (matches != 3)
	{
		std::cerr << RED << "Error: Invalid date format: " << dateStr << RESET << std::endl;
		return;
	}

	// if (_date.year < 2009 || _date.month < 1 || _date.month > 12 || _date.day < 1 || _date.day > 31)
	// 	throw std::runtime_error("Invalid date: " + dateStr);

	// parse value
	_value = atof(valueStr.c_str());

	if (_value < 0)
		std::cerr << RED << "Error: Negative value: " << _value << RESET << std::endl;
	else if (_value > 1000)
		std::cerr << RED << "Error: Value exceeds 1000: " << _value << RESET << std::endl;
	else
	std::cout << "Parsed Date: " << _date.year << "-" << _date.month << "-" << _date.day
			  << ", Value: " << _value << std::endl;

}

static bool isLeapYear(int year)
{
	return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int BitcoinExchange::daysInMonth()
{
	static const int days[] = { 31, 28, 31, 30,
										31, 30, 31, 31,
										30, 31, 30, 31 };

	if (_date.month == 2 && isLeapYear(_date.year))
		return 29;

	else if (_date.month < 1 || _date.month > 12)
		return 0;

	else
		return days[_date.month - 1];
}

bool	BitcoinExchange::validateDate()
{
	if (_date.year < 1 || _date.month < 1 || _date.month > 12 || _date.day < 1 || _date.day > 31)
	{
		std::cerr << RED << "Error: Invalid date: " << _date.year << "-" << _date.month << "-" << _date.day << RESET << std::endl;
		return false;
	}
	daysInMonth();
}

void	BitcoinExchange::processLine(const string_t& line)
{
	parseDate(line);
	validateDate();

}


void	BitcoinExchange::runFile(const string_t& input)
{
	std::ifstream file(input.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open file: " + input);

	string_t line;
	while (std::getline(file, line))
	{
		processLine(line);

		// std::cout << "Processing line: " << line << std::endl;
	}

	file.close();
}