/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:11:42 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/15 19:11:43 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "=== Creando ClapTrap ===" << std::endl;
	ClapTrap clap("CLAPPY");
	clap.attack("Enemy1");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n=== Creando ScavTrap ===" << std::endl;
	ScavTrap scav("SCAVVY");
	scav.attack("Enemy2");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << "\n=== Creando FragTrap ===" << std::endl;
	FragTrap frag("FRAGGY");
	frag.attack("Enemy3");
	frag.takeDamage(15);
	frag.beRepaired(5);
	frag.highFivesGuys();

	std::cout << "\n=== Creando DiamondTrap ===" << std::endl;
	DiamondTrap dia("DIAMMY");
	dia.attack("Enemy4");        
	dia.takeDamage(25);          
	dia.beRepaired(8);           
	dia.guardGate();             
	dia.highFivesGuys();         
	dia.whoAmI();                

	std::cout << "\n=== Fin del programa ===" << std::endl;
	return (0);
}
