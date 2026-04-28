#include "BitcoinExchange.hpp"

/*BitcoinExchange::BitcoinExchange(void)
{
}*/

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream	inputFile;
	std::stringstream	buffer;
	/*iinputFile.open(file);
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
	_content.erase();*/
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
		return (checkTopCsv(line)); //hacer alternativa para csv
	}
	/*if (i == 1 && split == ',')
	{
		i++;
		return (checkTopCsv(line));
	}*/
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

std::string	takeDate(std::string& line, int& i)
{
	std::stringstream	ss;
	std::string			date;
	//int	i = 0;
	while (line[i] && (std::isdigit(line[i]) || line[i] == '-'))
	{
		ss << line[i];
		i++;
	}
	ss >> date;
	return (date);
}
bool	takeAmmount(std::string& line, int& i, double& ammount)
{
	std::stringstream	ss;

	while (line[i] && std::isspace(line[i]))
		i++;
	if (line[i] == '|')
		i++;
	while (line[i])
	{
		ss << line[i];
		i++;
	}
	if ((!(ss >> ammount) || ss.bad()) || ammount < 0)
		return (false);
	return (true);
}

void	calculateLine(std::string& line, std::map<std::string, double>& csv)
{
	//std::stringstream	ss;
	std::string	date;
	double		ammount;
	line = trim(line);
	line = rtrim(line);

	if ((line[4] != '-' || line[7] != '-'))
	{
		std::cerr << "Bad input line\n";
		return ;
	}
	int	i = 0;
	date = takeDate(line, i);
	if (!takeAmmount(line, i, ammount))
	{
		std::cerr << "Bad ammount\n";
		return ;
	}
	std::map<std::string, double>::iterator it = csv.lower_bound(date);
	if (it != csv.end() && it ->first == date)
		std::cout << "Date: " << it->first << " | value: " << ammount * it->second << std::endl;
	else
	{
		if (it == csv.begin())
		{
			std::cerr << "No previous date\n";
			return ;
		}
		--it;
		std::cout << "Date: " << it->first << " | value: " << std::fixed << std::setprecision(2)<< ammount * it->second << std::endl;
	}
}

void	BitcoinExchange::calculate(char *file)
{
	std::ifstream	infile;
	std::string		line;
	std::map<std::string, double>& csv = getCsv();
	infile.open(file);
	if (infile.is_open())
	{
		int	i = 0;
		while (std::getline(infile, line))
		{
			if (i == 0)
				checkTop(line);
			else
				calculateLine(line, csv);
			i++;
		}
		if (infile.eof())
			std::cout << "Fin de archivo alcanzado\n";
		else
			std::cout << "Error de lectura\n";
	}
}