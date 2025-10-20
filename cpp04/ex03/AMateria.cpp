/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:04:44 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 15:04:46 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("undefined")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AMateria::~AMateria(void)
{
}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses an unknown materia on " << target.getName() << std::endl;
}