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
#include "Form.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat boss("Alice", 1);
		Bureaucrat intern("Bob", 150);
		Form formA("TopSecret", 50, 10);
		Form formB("BasicPaper", 120, 100);

		std::cout << boss << std::endl;
		std::cout << intern << std::endl;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;

		std::cout << "\n--- Try signing forms ---" << std::endl;

		intern.signForm(formA); // debería fallar (grade demasiado bajo)
		boss.signForm(formA);   // debería firmarse correctamente
		intern.signForm(formB); // debería firmarse correctamente

		std::cout << "\n--- Final status ---" << std::endl;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- Invalid form creation test ---" << std::endl;
	try
	{
		Form invalid("ImpossibleForm", 0, 10); // grade demasiado alto → excepción
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form invalid2("BadForm", 151, 100); // grade demasiado bajo → excepción
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
