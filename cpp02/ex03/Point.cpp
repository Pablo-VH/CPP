/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:29:27 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/15 13:29:31 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{}

Point::Point(const float x, const float y) : _x(x), _y(y)
{}

Point::Point(const Point& other) : _x(other._x), _y(other._y)
{}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Point::~Point(void)
{}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}
