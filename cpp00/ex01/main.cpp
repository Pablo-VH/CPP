/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:01:02 by pavicent          #+#    #+#             */
/*   Updated: 2025/04/03 13:01:06 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	input;

	while (1)
	{
		std::cout << "Enter: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\nEmpty" << input << std::endl;
			break ;
		}
		if (phone_book.check_input(input) == 1)
			return (1);
	}
	return (0);
}
