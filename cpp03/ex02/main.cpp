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

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Creando ClapTrap ===" << std::endl;
    ClapTrap clap("CLAPPY");
    clap.attack("Enemy1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n=== Creando ScavTrap ===" << std::endl;
    ScavTrap scav("SCAVVY");
    scav.attack("Enemy2");  // Usa versión de ScavTrap
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();       // Método exclusivo de ScavTrap

    std::cout << "\n=== Fin del programa ===" << std::endl;
    return 0;
}
