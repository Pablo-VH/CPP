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
#include <iostream>

int main(void)
{
   // std::cout << "=== Creando ClapTraps ===" << std::endl;
    ClapTrap ct1("Jack");
    ClapTrap ct2("Rose");

    //std::cout << "\n=== Probando ataques ===" << std::endl;
    ct1.attack("Rose");   // Jack ataca a Rose
    ct2.attack("Jack");   // Rose ataca a Jack

    //std::cout << "\n=== Probando recibir daño ===" << std::endl;
    ct1.takeDamage(3);    // Jack recibe 3 de daño
    ct2.takeDamage(5);    // Rose recibe 5 de daño

  //  std::cout << "\n=== Probando reparaciones ===" << std::endl;
    ct1.beRepaired(4);    // Jack se cura 4
    ct2.beRepaired(2);    // Rose se cura 2

   // std::cout << "\n=== Probando consumo de energía ===" << std::endl;
    for (int i = 0; i < 11; i++) {
        ct1.attack("Rose");   // Jack intentará atacar hasta quedarse sin energía
    }

   // std::cout << "\n=== Probando ClapTrap sin vida ===" << std::endl;
    ct2.takeDamage(20);       // Rose muere
    ct2.attack("Jack");       // Rose intenta atacar sin vida
    ct2.beRepaired(5);        // Rose intenta curarse sin vida

    std::cout << "\n=== Fin del programa ===\n" << std::endl;
    return 0;
}
