/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:32:01 by pavicent          #+#    #+#             */
/*   Updated: 2026/01/20 09:32:15 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	ScalarConverter::autoDetector(int prev, int pos)
{
	static int	matrix[][6] ={
		{AUT_ERR, AUT_SIG, AUT_NUM, AUT_CHR, AUT_FFF, AUT_ERR}, //INI
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
		else if (std::isdigit(literal[i]) && (prev == 5 || prev == 6))
			pos = 2;
		else if (std::isprint(literal[i]) && (literal[i] != 'f' && literal[i] != '.'))
			pos = 3;
		else if (literal[i] == 'f')
			pos = 4;
		else if (literal[i] == '.')
			pos = 5;
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

	if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		ScalarConverter::convertFromDouble(literal);
		return ;
	}
	else if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		ScalarConverter::convertFromFloat(literal);
		return ;
	}
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
	std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;;
}

void	ScalarConverter::convertFromInt(std::string const & literal)
{
	long	value;

	value = std::strtol(literal.c_str(), NULL, 10);
	if (value < INT_MIN || value > INT_MAX)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	int	i = static_cast<int>(value);
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	ScalarConverter::convertFromFloat(std::string const & literal)
{
	char	*endptr = NULL;
	float	value = std::strtof(literal.c_str(), &endptr);
	double	precise = std::strtod(literal.c_str(), NULL);

	if (*endptr != 'f' || *(endptr + 1) != '\0')
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	if (std::isnan(value) || value < static_cast<float>(INT_MIN) || value > static_cast<float>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	if ((value <= std::numeric_limits<float>::max() && value >= std::numeric_limits<float>::min()) && static_cast<double>(value) == precise)
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << value;
		std::cout << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value);
		std::cout << std::endl;
	}
	else
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << "\n";
	}
}

void	ScalarConverter::convertFromDouble(std::string const & literal)
{
	char	*endptr = NULL;
	double	value = std::strtod(literal.c_str(), &endptr);

	if (*endptr != '\0')
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	if (std::isnan(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value <= std::numeric_limits<double>::max() && value >= std::numeric_limits<double>::min())
	{
		std::cout << std::fixed << std::setprecision(1);
		float f = std::strtof(literal.c_str(), NULL);
		if (static_cast<double>(f) == value)
		{
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(value);
			std::cout << "f" << std::endl;
		}
		else
			std::cout << "float: impossible" << std::endl;
		std::cout << "double: " << value;
		std::cout << std::endl;
	}
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}
