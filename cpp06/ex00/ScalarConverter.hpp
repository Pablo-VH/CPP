/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:32:21 by pavicent          #+#    #+#             */
/*   Updated: 2026/01/20 09:32:23 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

# include <iostream>
# include <cctype>
# include <climits>
# include <limits>
# include <cmath>
# include <cstdlib>
# include <iomanip>

enum aut_type
{
	AUT_ERR,
	AUT_SIG,
	AUT_NUM,
	AUT_CHR,
	AUT_FFF,
	AUT_POI,
	AUT_DEC,
	AUT_COM
};

enum e_type
{
	TYPE__ERROR,
	TYPE___CHAR,
	TYPE____INT,
	TYPE__FLOAT,
	TYPE_DOUBLE
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
		~ScalarConverter();

		static int	detectType(std::string const & literal);
		static int	autoDetector(int prev, int pos);
		static void	convertFromChar(std::string const & literal);
		static void	convertFromInt(std::string const & literal);
		static void	convertFromFloat(std::string const & literal);
		static void	convertFromDouble(std::string const & literal);
	public:
		static void	convert(std::string const & literal);
};

#endif
