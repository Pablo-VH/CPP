/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:12:24 by pavicent          #+#    #+#             */
/*   Updated: 2025/08/25 18:12:44 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string.h>
# include <sstream>
//# include <ctype.h>
# include <stdlib.h>

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
		/*void	set_info(std::string first_name, std::string last_name,
					std::string nickname, long phone_number,
					std::string dark_secret);*/
};

#endif
