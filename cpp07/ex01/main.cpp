/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:03:02 by pavicent          #+#    #+#             */
/*   Updated: 2026/01/26 19:03:04 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// Función que modifica
void increment(int &n)
{
	n++;
}

int increment1(int &n)
{
	return n++;
}

// Función solo lectura
void printInt(int const &n)
{
	std::cout << n << std::endl;
}

void printString(std::string const &s)
{
	std::cout << s << std::endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::size_t len = 5;

	// Modificar elementos
	iter(arr, len, increment);
	
	// Leer elementos
	iter(arr, len, printInt);
	
	std::string strs[] = {"hola", "que", "tal"};
	iter(strs, 3, printString);
	
	const int constArr[] = {10, 20, 30};
	iter(constArr, 3, printInt);
	int i = increment1(arr[1]);
	std::cout << i << "\n";


	return 0;
}
