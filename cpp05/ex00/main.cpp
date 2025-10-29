/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:14:29 by pavicent          #+#    #+#             */
/*   Updated: 2025/10/29 19:14:30 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat a("Pepe", 55);
	Bureaucrat b("Juan", 33);
	Bureaucrat c("Paco", 1);
	try {
		Bureaucrat d("Adolfo", 151);
		std::cout << d.getName() << ", bureaucrat grade " << d.getGrade() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat e("Benito", 0);
		std::cout << e.getName() << ", bureaucrat grade " << e.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	
	try
	{
		a.incrementGrade();
		b.decrementGrade();
		c.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	return (0);
}
