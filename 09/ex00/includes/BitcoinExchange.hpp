#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <map>
#include <iomanip>
#include <limits>
#include <cmath>

#define RESET		"\033[0m"
#define YELLOW		"\033[33m"
#define BOLD		"\033[1m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define CYAN		"\033[36m"

#define MAX_VALUE	1000.0
#define DATA_FILE	"data.csv"
typedef std::string	string_t;

struct Date
{
	int year;
	int month;
	int day;

	bool 			operator<(const Date& other) const;
};


class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	
	BitcoinExchange& operator=(const BitcoinExchange& other);
	
	void 	runFile(const string_t& input);

private:
	void 	processLine(const string_t& line);
	void 	parseDate(const string_t& line);
	void	validateDate();
	void 	createBTCTable();
	void 	mapCurrentDate(const string_t& line);
	void 	printMatchedValue();
	
	Date					_date;
	double					_value;
	std::map<Date, double>	_btc;
	
};

std::ostream&	operator<<(std::ostream& os, const Date& date);

double			convertToDoubleOrThrow(const string_t& str);
bool			isLeapYear(int year);
int				daysInMonth(Date date);
string_t		trim(const string_t& str);
size_t			findSeparator(const string_t& line, char separator);