/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:17:01 by pavicent          #+#    #+#             */
/*   Updated: 2025/04/03 13:17:03 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int	i;
	Zombie	*horde;

	if (N <= 0)
		return (NULL);
	i = 0;
	horde = new Zombie[N];
	while (i < N)
	{
		horde[i].put_name(name);
		horde[i].announce();
		i++;
	}
	return (horde);
}
