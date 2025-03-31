/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:47:04 by pavicent          #+#    #+#             */
/*   Updated: 2025/03/17 11:47:05 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string.h>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		long		phone_number;
		std::string	dark_secret;

	public:
		Contact(void);
		~Contact(void);
		int		add_contact(int *number);
		int		check_phone(const char *n_contact);
		void	print_contact(int i);
		void	print_all(void);
		void	print_col(std::string str, int len_str);
		void	set_info(std::string first_name, std::string last_name,
					std::string nickname, long phone_number,
					std::string dark_secret);
};

class PhoneBook
{
private:
	Contact	person[8];
public:
	int	n_contact;
	PhoneBook(void);
	~PhoneBook(void);
	int	check_input(std::string input);
};


#endif
