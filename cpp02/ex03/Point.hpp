/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:29:37 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/15 13:29:39 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP_
#define POINT_HPP_

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

	Fixed getX() const;
	Fixed getY() const;
};

#endif
