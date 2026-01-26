/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:03:09 by pavicent          #+#    #+#             */
/*   Updated: 2026/01/26 19:03:10 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP_
#define ITER_HPP_

# include <iostream>
# include <string>

template <typename T>
void	iter(T *array, std::size_t const length, void(*f)(T &))
{
	std::size_t	i;

	i = 0;
	while (i < length)
		f(array[i++]);
}

template <typename T>
void	iter(T const *array, std::size_t const length, void(*f)(T const &))
{
	std::size_t	i;

	i = 0;
	while (i < length)
		f(array[i++]);
}

#endif
