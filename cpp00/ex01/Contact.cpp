/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:46:44 by pavicent          #+#    #+#             */
/*   Updated: 2025/04/01 13:56:04 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	Contact::print_all(void)
{
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Dark secret: " << this->dark_secret << std::endl;
}

void	Contact::print_col(std::string str, int len_str)
{
	int	j;

	j = 0;
	if (len_str >= 10)
	{
		while (j < 9 && j < len_str)
			std::cout << str[j++];
		std::cout << ".";
	}
	else
		std::cout << std::setw(10) << str;
}

void	Contact::print_contact(int i)
{
	std::stringstream	index;
	index << (i + 1);
	print_col(index.str(), 1);
	std::cout << "|";
	print_col(this->first_name, first_name.length());
	std::cout << "|";
	print_col(this->last_name, last_name.length());
	std::cout << "|";
	print_col(this->nickname, nickname.length());
	std::cout << "\n";
}

int	Contact::check_phone(const char *n_contact)
{
	int	i;

	if (strlen(n_contact) != 9)
	{
		std::cout << "Invalid number" << std::endl;
		return (1);
	}
	i = 0;
	while (n_contact[i])
	{
		if (n_contact[i] < '0' || n_contact[i] > '9')
		{
			std::cout << "Invalid number" << std::endl;
			return (1);
		}
		i++;
	}
	this->phone_number = atol(n_contact);
	return (0);
}

int	Contact::add_contact(int *number)
{
	std::string	input[5];
	std::string	types[5];
	int			i;

	types[0] = "	First_name";
	types[1] = "	Last_name";
	types[2] = "	Nickname";
	types[3] = "	Phone_number";
	types[4] = "	Dark_secret";
	i = 0;
	while (i < 5)
	{
		std::cout << types[i] << ": ";
		std::getline(std::cin, input[i]);
		if (std::cin.eof())
		{
			std::cout << "\nEof" << std::endl;
			return (1);
		}
		if (input[i].empty())
		{
			std::cout << "Empty contact info" << std::endl;
			(*number)--;
			return (0);
		}
		if (i == 3)
		{
			if (check_phone(input[i].c_str()) == 1)
			{
				(*number)--;
				return (0);
			}
		}
		i++;
	}
	this->first_name = input[0];
	this->last_name = input[1];
	this->nickname = input[2];
	this->dark_secret = input[4];
	return (0);
}

Contact::Contact(void)
{
	std::cout << "Contact constructor" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor" << std::endl;
}
