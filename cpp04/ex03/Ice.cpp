/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:05:38 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 15:05:39 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(const Ice& other) : AMateria(other)
{
}

Ice&	Ice::operator=(const Ice& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}

Ice::~Ice(void)
{
}