/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:46:44 by pavicent          #+#    #+#             */
/*   Updated: 2025/03/17 11:46:46 by pavicent         ###   ########.fr       */
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
	int	spaces;
	int	j;
	int	i;

	i = 0;
	j = 0;
	spaces = 10 - len_str;
	while (i < spaces)
	{
		std::cout << " ";
		i++;
	}
	while (j < 9 && j < len_str)
		std::cout << str[j++];
	if (len_str >= 10)
		std::cout << ".";
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
		std::cout << "Invald number" << std::endl;
		return (1);
	}
	i = 0;
	while (n_contact[i])
	{
		if (n_contact[i] < 0 || n_contact[i] > 9)
		{
			std::cout << "Invald number" << std::endl;
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
		std::cout << ": ";
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
				return (1);
			}
		}
	}
	this->first_name = input[0];
	this->last_name = input[1];
	this->nickname = input[2];
	this->dark_secret = input[4];
	return (0);
}

void	Contact::set_info(std::string first_name, std::string last_name, std::string nickname, long phone_number, std::string dark_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->dark_secret = dark_secret;
}
Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}
