/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:05:04 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 15:05:06 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP_
#define AMATERIA_HPP_

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria(void);

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};

#endif
