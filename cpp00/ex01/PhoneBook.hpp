/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:47:04 by pavicent          #+#    #+#             */
/*   Updated: 2025/04/01 13:38:05 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string.h>
# include <sstream>
//# include <ctype.h>
# include <stdlib.h>
# include "Contact.hpp"

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
