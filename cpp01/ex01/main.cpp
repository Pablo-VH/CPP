/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:22:28 by pavicent          #+#    #+#             */
/*   Updated: 2025/03/13 11:22:30 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*new_Zombie;
	int		i;
	int		N;
	
	i = 0;
	N = 5;
	new_Zombie = zombieHorde(N, "Foo");
	std::cout << "\n";
	while (i < N)
	{
		std::cout << "Zombie " << i + 1 << ": ";
		new_Zombie[i].announce();
		std::cout << "\n";
		i++;
	}
	delete[] (new_Zombie);
	
	return (0);
}
