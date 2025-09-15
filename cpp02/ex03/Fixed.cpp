/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:04:35 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/05 11:04:37 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int n)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_value = n << _fbits;
}

Fixed::Fixed(const float f)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << _fbits));
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << _fbits);
}

int		Fixed::toInt(void) const
{
	return this->_value >> _fbits;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed		res;
	long long	mul;

	mul = this->_value * other._value;
	res.setRawBits(mul >> _fbits);
	return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed		res;
	long long	div;

	div = (this->_value << _fbits) / other._value;
	res.setRawBits(div);
	return (res);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed	res;

	res.setRawBits(this->_value + other._value);
	return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed	res;

	res.setRawBits(this->_value - other._value);
	return (res);
}

Fixed&	Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	_value++;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	_value--;
	return (tmp);
}

/*Fixed&	Fixed::operator--(int)
{
	_value--;
	return (*this);
}*/

bool	Fixed::operator!=(const Fixed& other) const
{
	if (this->_value != other._value)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& other) const
{
	if (this->_value == other._value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	if (this->_value >= other._value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	if (this->_value <= other._value)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& other) const
{
	if (this->_value > other._value)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& other) const
{
	if (this->_value < other._value)
		return (true);
	return (false);
}

const Fixed&	Fixed::max(const Fixed& one, const Fixed& two)
{
	if (one._value > two._value)
		return (one);
	return (two);
}

const Fixed&	Fixed::min(const Fixed& one, const Fixed& two)
{
	if (one._value < two._value)
		return (one);
	return (two);
}

Fixed&	Fixed::max(Fixed& one, Fixed& two)
{
	if (one._value > two._value)
		return (one);
	return (two);
}

Fixed&	Fixed::min(Fixed& one, Fixed& two)
{
	if (one._value < two._value)
		return (one);
	return (two);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}