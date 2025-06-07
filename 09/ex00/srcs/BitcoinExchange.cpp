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

/************************************************************************************************/


void	BitcoinExchange::printMatchedValue()
{
	std::map<Date, double>::iterator it = _btc.upper_bound(_date);
	
	if (it != _btc.begin()){
		it--;
	}
	
	std::cout << _date << " => " << _value << " = " << (it->second * _value) << std::endl;
}

void	BitcoinExchange::validateDate()
{
	if (_date.year < 1 || _date.month < 1 || _date.month > 12 || _date.day < 1 || _date.day > 31)
	throw std::runtime_error("Invalid date");
	
	if (_date.day > daysInMonth(_date))
	throw std::runtime_error("Invalid day for the month");
	
	if (_date.year < 2009 || (_date.year == 2009 && _date.month < 1)
	|| (_date.year == 2009 && _date.month == 1 && _date.day < 2))
	throw std::runtime_error("Date is before the start of Bitcoin data (2009-01-02)");
}

void	BitcoinExchange::parseDate(const string_t& line)
{
	size_t pos = findSeparator(line, '|');

	string_t dateStr = line.substr(0, pos);
	string_t valueStr = line.substr(pos + 1);

	dateStr = trim(dateStr);
	valueStr = trim(valueStr);

	char extra;
	int matches = std::sscanf(dateStr.c_str(), "%d-%d-%d%c"
					, &_date.year, &_date.month, &_date.day, &extra);
	if (matches != 3)
		throw std::runtime_error("Garbage values after date");

	_value = convertToDoubleOrThrow(valueStr);

	if (_value < 0)
		throw std::out_of_range("Negative value");
	else if (_value > MAX_VALUE)
		throw std::out_of_range("Value exceeds maximum limit");
}

void	BitcoinExchange::processLine(const string_t& line)
{
	try{
		parseDate(line);
		validateDate();
		printMatchedValue();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << YELLOW << line << RESET << " - " << e.what() << std::endl;
		return;
	}
}

void	BitcoinExchange::runFile(const string_t& input)
{
	std::ifstream file(input.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open file: " + input);

	createBTCTable();

	string_t line;
	bool firstLine = true;
	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue;
		}
		processLine(line);
	}

	file.close();
}

bool Date::operator<(const Date& other) const
{
	if (year != other.year)
		return year < other.year;
	if (month != other.month)
		return month < other.month;
	return day < other.day;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os	<< date.year << "-" 
    	<< std::setfill('0') << std::setw(2) << date.month << "-"
    	<< std::setfill('0') << std::setw(2) << date.day;
	return os;
}