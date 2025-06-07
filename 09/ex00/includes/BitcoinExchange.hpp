#pragma once

#include <iostream>
#include <iostream>
#include <exception>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <map>


#define RESET		"\033[0m"
#define YELLOW		"\033[33m"
#define BOLD		"\033[1m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define CYAN		"\033[36m"

#define MAX_VALUE	1000.0
#define DATA_FILE	"data.csv"
typedef std::string string_t;

struct Date
{
	int year;
	int month;
	int day;
	bool operator<(const Date& other) const;
};

/**
 * @todo: change the logic error so instead of having prints
 * to std::cerr, throw exceptions with the error messages
 * to be caught inside processLine, and use bools
 */
class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange& other);

	void 	runFile(const string_t& input);
	void 	processLine(const string_t& line);
	void 	parseDate(const string_t& line);
	bool	validateDate();
	int		daysInMonth();
	void 	createBTCTable();
	void 	mapCurrentDate(const string_t& line);
	void 	printMatchedValue();

private:
	Date					_date;
	double					_value;
	std::map<Date, double>	_btc;

};