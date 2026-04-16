#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(char *file)
{
	std::ifstream	inputFile;
	inputFile.open(file);
	if (inputFile.is_open())
	{
		std::stringstream	buffer;
		buffer << inputFile.rdbuf();
		_content = buffer.str();
		tokenize(_content);
	}
}

BitcoinExchange::~BitcoinExchange()
{
}

const char* InvalidContentFile::what() const throw()
{
	return ("Invalid content file");
}

const char* InvalidDate::what() const throw()
{
	return ("Invalid date");
}