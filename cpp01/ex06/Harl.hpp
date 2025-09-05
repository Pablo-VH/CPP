/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:23:34 by pavicent          #+#    #+#             */
/*   Updated: 2025/08/25 18:23:38 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP_
#define HARL_HPP_

# include <iostream>
# include <fstream>

class Harl
{
	private:
		void	debug(void);
		void	info( void );
		void	warning( void );
		void	error( void );
	public:
		void	complain( std::string level );
		Harl( void );
		~Harl( void );
};

#endif