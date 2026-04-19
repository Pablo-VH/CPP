#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(char *file)
{
	std::ifstream	inputFile;
	std::stringstream	buffer;
	inputFile.open(file);
	if (inputFile.is_open())
	{
		buffer << inputFile.rdbuf();
		_content = buffer.str();
		tokenize(_content, '|');
	}
	else
		throw FailOpeningFile();
	buffer.str("");
	buffer.clear();
	inputFile.close();
	_content.erase();
	inputFile.open("data.csv");
	if (inputFile.is_open())
	{
		buffer << inputFile.rdbuf();
		_content = buffer.str();
		tokenize(_content, ',');
	}
	else
		throw FailOpeningFile();
	inputFile.close();
	_content.erase();
	buffer.str("");
	buffer.clear();
}

BitcoinExchange::~BitcoinExchange()
{
}

const char* FailOpeningFile::what() const throw()
{
	return ("Fail opening file");
}

const char* InvalidContentFile::what() const throw()
{
	return ("Invalid content file");
}

const char* InvalidDate::what() const throw()
{
	return ("Invalid date");
}

void	BitcoinExchange::setInput(std::string& key, double value)
{
	if (value > 1000)
		throw InvalidContentFile();
	_input.insert(std::make_pair(key, value));
}

void	BitcoinExchange::setCsv(std::string& key, double value)
{
	if (value > INT_MAX)
		throw InvalidContentFile();
	_csv.insert(std::make_pair(key, value)); 
}

void	BitcoinExchange::checkLine(std::string& line, char split)
{
	static int	i = 0;
	std::stringstream	ss;
	std::stringstream	ss2;
	std::string			numstr;
	std::string			key;
	double				value;
	line = trim(line);
	line = rtrim(line);
	if (i == 0)
	{
		i++;
		return (checkTop(line)); //hacer alternativa para csv
	}
	if (i == 1 && split == ',')
	{
		i++;
		return (checkTopCsv(line));
	}
	if (line[4] != '-' || line[7] != '-')
		throw InvalidContentFile();
	int	j = 0;
	std::string::iterator it = line.begin();
	std::string::iterator end = line.end();
	while (it != end)
	{
		if (!std::isdigit(*it) && (j != 4 && j != 7) && (j < 10))
			throw std::exception();
		if (*it == split)
			break ;
		j++;
		ss << *it;
		++it;
	}
	key = ss.str();
	checkDate(key);
	ss.str("");
	ss.clear();
	if (*it == split)
		++it;
	bool	nums = false;
	while (it != end && std::isspace(*it))
		++it;
	while (it != end)
	{
		if (*it == '.')
		{
			ss << *it;
			++it;
		}
		while (it != end && std::isdigit(*it))
		{
			nums = true;
			ss << *it;
			++it;
		}
		if (*it && ((!std::isdigit(*it) && *it != '.') || std::isspace(*it)))
		{
			std::cout << *it << std::endl;
			throw InvalidContentFile();
		}
	}
	if (it != end || nums == false)
		throw InvalidContentFile();
	numstr = ss.str();
	ss >> value;	
	if (value < 0)
		throw InvalidContentFile();
	if (split == '|')
		return (setInput(key, value));
	setCsv(key, value);
}

void	BitcoinExchange::tokenize(std::string& tokens, char split)
{
	std::stringstream ss;
	std::string	line;
	for (std::string::iterator it = tokens.begin(); it != tokens.end(); ++it)
	{
		if (*it == '\n')
		{
			if (!line.empty())
				line.erase();
			ss << *it;
			line = ss.str();
			if (line == "\n")
				continue;
			checkLine(line, split);
			ss.str("");
			ss.clear();
		}
		else if(it == tokens.end() -1)
		{
			if (!line.empty())
				line.erase();
			ss << *it;
			line = ss.str();
			checkLine(line, split);
			ss.str("");
			ss.clear();
		}
		else
			ss << *it;
	}
}

std::multimap<std::string, double>&	BitcoinExchange::getInput()
{
	return (_input);
}

std::map<std::string, double>&	BitcoinExchange::getCsv()
{
	return (_csv);
}