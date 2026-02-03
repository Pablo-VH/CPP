/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:49:54 by pavicent          #+#    #+#             */
/*   Updated: 2026/02/02 09:49:58 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP_
#define EASYFIND_TPP_

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::exception();
	return it;
}

#endif
