#include "BitcoinExchange.hpp"

void	BitcoinExchange::mapCurrentDate(const string_t& line)
{
	Date btcDate;

	size_t pos = findSeparator(line, ',');
	string_t dateStr = line.substr(0, pos);
	string_t valueStr = line.substr(pos + 1);

	std::sscanf(dateStr.c_str(), "%d-%d-%d"
				, &btcDate.year, &btcDate.month, &btcDate.day);

	_btc[btcDate] = atof(valueStr.c_str());
}

void	BitcoinExchange::createBTCTable()
{
	std::ifstream file(DATA_FILE);
	if (!file.is_open())
		throw std::runtime_error(string_t("Could not open data file: ") + DATA_FILE);
	
	string_t line;

	while (std::getline(file, line))
		mapCurrentDate(line);
	
	file.close();
}