/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:35:10 by pavicent          #+#    #+#             */
/*   Updated: 2026/01/27 09:35:11 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
	try
	{
		Array<int> a(5);

		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i * 10;

		Array<int> b = a; // copy constructor
		b[0] = 42;

		std::cout << "Array a:" << std::endl;
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << std::endl;

		std::cout << "Array b:" << std::endl;
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << b[i] << std::endl;

		std::cout << "Out of bounds test:" << std::endl;
		std::cout << a[10] << std::endl; // debe lanzar excepción
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught" << std::endl;
	}

	return 0;
}
