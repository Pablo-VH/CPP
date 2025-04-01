/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:46:53 by pavicent          #+#    #+#             */
/*   Updated: 2025/04/01 13:29:20 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::check_input(std::string input)
{
	int			i;
	int			number;
	std::string	search_index;

	i = 0;
	if (input == "ADD")
	{
		if (person[n_contact % 8].add_contact(&n_contact) == 1)
			return (1);
		this->n_contact++;
		std::cout << "N_CONTACT: " << n_contact << std::endl;
	}
	else if (input == "SEARCH")
	{
		while (i < n_contact && i < 8)
		{
			person[(i % 8)].print_contact(i);
			i++;
		}
		std::cout << "	Enter index: ";
		std::getline(std::cin, search_index);
		if (std::cin.eof())
		{
			std::cout << "\nEmpty" << input << std::endl;
			return (1);
		}
		std::stringstream index_new(search_index);
		index_new >> (number);
		if ((number < 1 || number > 8) || number > n_contact)
		{
			std::cout << "Wrong index" << std::endl;
			return (0);
		}
		person[(number - 1) % 8].print_all();
	}
	else if (input == "EXIT")
	{
		return (1);
	}
	return (0);
}

PhoneBook::PhoneBook(void)
{
	this->n_contact = 0;
	std::cout << "PhoneBook constructor " << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor" << std::endl;
}
