/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:14:56 by pavicent          #+#    #+#             */
/*   Updated: 2025/10/29 19:14:57 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::srand(std::time(NULL)); // Sembrar una sola vez

	std::cout << "=== Creating Bureaucrats ===" << std::endl;
	Bureaucrat alice("Alice", 1);
	Bureaucrat bob("Bob", 45);
	Bureaucrat charlie("Charlie", 140);
	Bureaucrat dave("Dave", 150);
	std::cout << std::endl;

	std::cout << "=== Creating Forms ===" << std::endl;
	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("Marvin");
	PresidentialPardonForm pardon("Arthur");
	std::cout << std::endl;

	std::cout << "=== Trying to sign forms ===" << std::endl;
	dave.signForm(shrub);    // debería fallar (grado demasiado bajo)
	charlie.signForm(shrub); // debería firmar
	bob.signForm(robo);      // debería firmar
	alice.signForm(pardon);  // debería firmar
	std::cout << std::endl;

	std::cout << "=== Trying to execute forms ===" << std::endl;
	dave.executeForm(shrub);    // debería fallar (muy bajo)
	charlie.executeForm(shrub); // debería ejecutar -> crea home_shrubbery
	bob.executeForm(robo);      // debería ejecutar con probabilidad 50%
	alice.executeForm(pardon);  // debería ejecutar sin problema
	std::cout << std::endl;

	std::cout << "=== Program end ===" << std::endl;
	return 0;
}
