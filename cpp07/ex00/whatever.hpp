/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:02:31 by pavicent          #+#    #+#             */
/*   Updated: 2026/01/26 19:02:32 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP_
#define WHATEVER_HPP_

#include <iostream>

template <typename T>
void	swap(T &x, T &y)
{
	T	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T const	&min(T &x, T &y)
{
	if (x < y)
		return (x);
	return (y);
}

template <typename T>
T const	&max(T &x, T &y)
{
	if (x > y)
		return (x);
	return (y);
}

#endif
