#include "ScalarConverter.hpp"

int	ScalarConverter::autoDetector(int prev, int pos)
{
	static int	matrix[][6] ={
		{AUT_ERR, AUT_SIG, AUT_NUM, AUT_CHR, AUT_FFF, AUT_POI}, //INI
		{AUT_ERR, AUT_ERR, AUT_NUM, AUT_ERR, AUT_ERR, AUT_ERR}, //SIGN
		{AUT_ERR, AUT_ERR, AUT_NUM, AUT_ERR, AUT_ERR, AUT_POI}, //NUM
		{AUT_ERR, AUT_ERR, AUT_ERR, AUT_ERR, AUT_ERR, AUT_ERR}, //CHAR
		{AUT_ERR, AUT_ERR, AUT_ERR, AUT_ERR, AUT_ERR, AUT_ERR}, //F
		{AUT_ERR, AUT_ERR, AUT_DEC, AUT_ERR, AUT_ERR, AUT_ERR}, //'.'
		{AUT_ERR, AUT_ERR, AUT_DEC, AUT_ERR, AUT_FFF, AUT_ERR}  //AFTER '.'
	};
	return (matrix[prev][pos]);
}

int	ScalarConverter::detectType(std::string const & literal)
{
	int	i;
	int pos;
	int	prev;

	i = 0;
	if (literal.length() == 1 && std::isprint(literal[i]) && !std::isdigit(literal[i]))
		return (TYPE___CHAR);
	prev = i;
	while (literal[i])
	{
		pos = 0;
		if ((literal[i] == '+' || literal[i] == '-') && prev == 0)
			pos = 1;
		else if (std::isdigit(literal[i]) && prev < 4)
			pos = 2;
		else if (std::isprint(literal[i]) && (literal[i] != 'f' && literal[i] != '.'))
			pos = 3;
		else if (literal[i] == 'f')
			pos = 4;
		else if (literal[i] == '.')
			pos = 5;
		else if (std::isdigit(literal[i]) && prev == 5)
			pos = 6;
		prev = ScalarConverter::autoDetector(prev, pos);
		if (prev == 0)
			return (TYPE__ERROR);
		i++;
	}
	if (prev == AUT_NUM)
		return (TYPE____INT);
	else if (prev == AUT_FFF)
		return (TYPE__FLOAT);
	else if (prev == AUT_DEC)
		return (TYPE_DOUBLE);
	else
		return(TYPE__ERROR);
}

void	ScalarConverter::convert(std::string const & literal)
{
	int	type;
	type = ScalarConverter::detectType(literal);
	switch (type)
	{
	case TYPE__ERROR:
		std::cout << "Invalid input" << std::endl;
		break ;
	case TYPE___CHAR:
		ScalarConverter::convertFromChar(literal);
		break ;
	case TYPE____INT:
		ScalarConverter::convertFromInt(literal);
		break ;
	case TYPE__FLOAT:
		ScalarConverter::convertFromFloat(literal);
		break ;
	case TYPE_DOUBLE:
		ScalarConverter::convertFromDouble(literal);
		break ;
	default:
		break ;
	}
}

void	ScalarConverter::convertFromChar(std::string const & literal)
{
	double	d;
	int		i;
	float	f;
	char	c;

	c = literal[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	std::cout << "char: '" << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;;
}

void	ScalarConverter::convertFromInt(std::string const & literal)
{}
void	ScalarConverter::convertFromFloat(std::string const & literal)
{}
void	ScalarConverter::convertFromDouble(std::string const & literal)
{}