/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:23:16 by pavicent          #+#    #+#             */
/*   Updated: 2025/03/13 11:23:21 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_
# include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie( void );
		~Zombie( void );
		void	announce( void );
		void	put_name( std::string name );

};

Zombie* zombieHorde( int N, std::string name );

#endif
