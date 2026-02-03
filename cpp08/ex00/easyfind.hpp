/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:49:54 by pavicent          #+#    #+#             */
/*   Updated: 2026/02/02 09:49:58 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP_
#define EASYFIND_HPP_

# include <iostream>
# include <algorithm>
# include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int value);

# include "easyfind.tpp"

#endif
