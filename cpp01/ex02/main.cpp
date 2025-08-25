/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:14:45 by pavicent          #+#    #+#             */
/*   Updated: 2025/08/25 18:14:47 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main ( void )
{
	std::string *ptr;
	std::string str = "HI THIS IS BRAIN";
	std::string	&ref = str;
	ptr = &str;

	std::cout << *ptr << std::endl;
	std::cout << str << std::endl;
	std::cout << ref << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ref << std::endl;
	std::cout << &str << std::endl;
}
