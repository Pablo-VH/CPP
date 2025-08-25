/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:21:09 by pavicent          #+#    #+#             */
/*   Updated: 2025/08/25 18:21:10 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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

