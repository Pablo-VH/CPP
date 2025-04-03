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

int	main( void )
{
	Zombie	*new_Zombie;
	
	new_Zombie = newZombie("Foo");
	new_Zombie->announce();
	delete(new_Zombie);
	randomChump("Victor");
	return (0);
}
