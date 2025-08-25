/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:17:01 by pavicent          #+#    #+#             */
/*   Updated: 2025/08/25 18:17:03 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
const	std::string& Weapon::getType(void)
{
	return(this->_type);
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Weapon constructor" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon destructor" << std::endl;
}
