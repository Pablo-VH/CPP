#include "utils.hpp"

std::string rtrim(std::string& line)
{
    size_t end = line.size() - 1;

    if (line.empty())
        return (line);
    while ((end > 0 && std::isspace(static_cast<unsigned char>(line[end]))))
        end--;
    if (end == 0 && std::isspace(static_cast<unsigned char>(line[0])))
        return ("");
    return (line.substr(0, end + 1));
}

std::string trim(std::string& line)
{
    size_t i = 0;

    if (line.empty())
        return (line);
    while (line[i] && std::isspace(static_cast<unsigned char>(line[i])))
        i++;
    if (i == line.size())
        return ("");
    return (line.substr(i, line.size() - i));
}

static int	chooseTopState(int prev, int pos)
{
	static int matrix[][10] = {
		{1, 2, 1, 1,  1, 1, 1, 1,  1,  1}, //0 INI
		{1, 1, 1, 1,  1, 1, 1, 1,  1,  1}, //1 ERR
		{1, 1, 3, 1,  1, 1, 1, 1,  1,  1}, //2 D
		{1, 1, 1, 4,  1, 1, 1, 1,  1,  1}, //3 A
		{1, 1, 1, 1,  5, 1, 1, 1,  1,  1}, //4 T
		{1, 1, 1, 1,  1, 6, 1, 1,  1,  1}, //5 E
		{1, 1, 1, 1,  1, 1, 7, 1,  1,  1}, //6 |
		{1, 1, 8, 1,  1, 1, 1, 1,  1,  1}, //7 V
		{1, 1, 1, 1,  1, 1, 1, 9,  1,  1}, //8 A
		{1, 1, 1, 1,  1, 1, 1, 1, 10,  1}, //9 L
		{1, 1, 1, 1, 10, 1, 1, 1,  1, 11}, //10 U
		{1, 1, 1, 1,  1, 1, 1, 1,  1,  1} //11 E
	};
	return (matrix[prev][pos]);
}

void	checkTop(std::string& line)
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
		{
			std::cout << *it << std::endl;
			throw InvalidContentFile();
		}
	}
}

static int	chooseTopStateCsv(int prev, int pos)
{
	static int matrix[][15] = {
		{1, 2,  1,  1,   1, 1, 1, 1,  1,  1,  1,  1,  1}, //0 INI
		{1, 1,  1,  1,   1, 1, 1, 1,  1,  1,  1,  1,  1}, //1 ERR
		{1, 1,  3,  1,   1, 1, 1, 1,  1,  1,  1,  1,  1}, //2 D
		{1, 1,  1,  4,   1, 1, 1, 1,  1,  1,  1,  1,  1}, //3 A
		{1, 1,  1,  1,   5, 1, 1, 1,  1,  1,  1,  1,  1}, //4 T
		{1, 1,  1,  1,   1, 6, 1, 1,  1,  1,  1,  1,  1}, //5 E
		{1, 1,  1,  1,   7, 1, 1, 1,  1,  1,  1,  1,  1}, //6 ,
		{1, 1,  1,  1,   1, 1, 8, 1,  1,  1,  1,  1,  1}, //7 E
		{1, 1,  1,  1,   1, 1, 1, 9,  1,  1,  1,  1,  1}, //8 X
		{1, 1,  1,  1,   1, 1, 1, 1, 10,  1,  1,  1,  1}, //9 C
		{1, 1, 11,  1,   1, 1, 1, 1,  1,  1,  1,  1,  1}, //10 H
		{1, 1,  1,  1,   1, 1, 1, 1,  1, 12,  1,  1,  1}, //11 A
		{1, 1,  1,  1,   1, 1, 1, 1,  1,  1, 13,  1,  1}, //12 N
		{1, 1,  1,  1,  14, 1, 1, 1,  1,  1,  1,  1,  1}, //13 G
		{1, 1,  1,  1,   1, 1, 1, 1,  1,  1,  1, 15,  1}, //14 E
		{1, 1,  1,  1,   1, 1, 1, 1,  1,  1,  1,  1, 16}, //15 _
		{1, 1, 17,  1,   1, 1, 1, 1,  1,  1,  1,  1,  1}, //16 R
		{1, 1,  1, 18,   1, 1, 1, 1,  1,  1,  1,  1,  1}, //17 A
		{1, 1,  1,  1,  19, 1, 1, 1,  1,  1,  1,  1,  1}, //18 T
		{1, 1,  1,  1,   1, 1, 1, 1,  1,  1,  1,  1,  1}, //19 E
	//	err d   a   t    e  ,  x  c   h   n   g   _   r
//pos =  0  1   2   3    4  5  6  7   8   9  10  11  12
	};
	return (matrix[prev][pos]);
}

void	checkTopCsv(std::string& line)
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
		else if (*it == ',')
			state = 5;
		else if (*it == 'x' || *it == 'X')
			state = 6;
		else if (*it == 'c' || *it == 'C')
			state = 7;
		else if (*it == 'h' || *it == 'H')
			state = 8;
		else if (*it == 'n' || *it == 'N')
			state = 9;
		else if (*it == 'g' || *it == 'G')
			state = 10;
		else if (*it == '_')
			state = 11;
		else if (*it == 'r' || *it == 'R')
			state = 12;
		else if (std::isspace(*it) && (prev == 5 || prev == 6))
			continue;
		prev = chooseTopStateCsv(prev, state);
		if (prev == 1)
		{
			std::cout << *it << std::endl;
			throw InvalidContentFile();
		}
	}
}

static bool	checkYear(int year, std::string& str)
{
	if (year < 0 || str.length() > 4)
	{
		std::cout << "aqui888\n" << str << std::endl;
		throw InvalidDate();
	}
	if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0))
		return (true);
	return (false);
}

static void	checkMD(int day, int month, bool leapYear)
{
	if ((day > 31 || day <= 0) || (month <= 0 || month >12))
	{
		std::cout << "aqui1\n";
		throw InvalidDate();
	}
	if ((day == 31 && ((month < 8 && month % 2 == 0) || (month > 7 && month % 2 != 0))) || (month == 2 && day > 29))
	{
		std::cout << day << " " << month << "aqui\n";
		throw InvalidDate();
	}
	if (leapYear == false && (month == 2 && day == 29))
	{
		std::cout << "aqui3\n";
		throw InvalidDate();
	}
}

void checkDate(std::string& date)
{
	std::stringstream	ss;
	int					auxNum;
	int					day;
	std::string			auxStr;
	std::string			dayStr;
	std::string			dateTrimmed = rtrim(date);
	std::string::iterator it = dateTrimmed.begin();
	std::string::iterator end = dateTrimmed.end();
	while(it != end)
	{
		if(*it == '-')
		{
			++it;
			break;
		}
		ss << *it;
		++it;
	}
	bool leapYear = false;
	auxStr = ss.str();
	ss >> auxNum;
	ss.str("");
	ss.clear();
	leapYear = checkYear(auxNum, auxStr);
	while (it != end)
	{
		if(*it == '-')
		{
			++it;
			break;
		}
		ss << *it;
		++it;
	}
	auxStr = ss.str();
	ss >> auxNum;
	ss.str("");
	ss.clear();
	while (it != end)
	{
		ss << *it;
		++it;
	}
	dayStr = ss.str();
	ss >> day;
	ss.str("");
	ss.clear();
	if ((dayStr.length() != 2 || auxStr.length() != 2) || it != end)
	{
		std::cout << "aqui777\n" << dayStr << "\n" << auxStr<< "\n";
		throw InvalidDate();
	}
	checkMD(day, auxNum, leapYear);
}
