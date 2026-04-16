#include "BitcoinExchange.hpp"

int	chooseTopState(int prev, int pos)
{
	static int matrix[][10] = {
		{}, //INI
		{}, //ERR
		{}, //D
		{}, //A
		{}, //T
		{}, //E
		{}, //V
		{}, //L
		{} //U
	};
	return (matrix[prev][pos]);
}

static void	checkTop(std::string line)
{
	int	state;
	int	prev = 0;
	for (std::string::iterator it = line.begin(); it != line.end(); ++it)
	{
		state = 0;
		if (*it == 'd' || *it == 'D')
			state = 1;
		else if (*it == 'a' || *it == 'A')
			state = 2;
		else if (*it == 't' || *it == 'T')
			state = 3;
		else if (*it == 'e' || *it == 'E')
			state = 4;
		else if (*it == '|')
			state = 5;
		else if (*it == 'v' || *it == 'V')
			state = 6;
		else if (*it == 'l' || *it == 'L')
			state = 7;
		else if (*it == 'u' || *it == 'U')
			state = 8;
		else if (*it == ' ')
			continue;
		prev = chooseTopState(prev, state);
		if (prev == 1)
			throw std::exception();
	}
}
static void	checkLine(std::string line)
{
	static int	i = 0;
	std::cout << "Line: " << line << std::endl;
	if (i == 0)
		return (checkTop(line));
}

void	tokenize(std::string tokens)
{
	///std::string::iterator	it = tokens.begin();
	//std::string::iterator	end = tokens.end();
	std::stringstream ss;
	std::string	line;
	for (std::string::iterator it = tokens.begin(); it != tokens.end(); ++it)
	{
		if (*it == '\n')
		{
			if (!line.empty())
				line.erase();
			line = ss.str();
			//std::cout << "Line ss: " << ss.str() << std::endl;
			checkLine(line);
			ss.str("");
			ss.clear();
		}
		else if(it == tokens.end() -1)
		{
			if (!line.empty())
				line.erase();
			ss << *it;
			line = ss.str();
			checkLine(line);
			ss.str("");
			ss.clear();
		}
		else
			ss << *it;
	}
}