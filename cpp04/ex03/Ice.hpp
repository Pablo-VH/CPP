/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:05:42 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 15:05:44 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP_
#define ICE_HPP_

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		~Ice(void);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif