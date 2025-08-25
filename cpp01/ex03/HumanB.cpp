/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:16:22 by pavicent          #+#    #+#             */
/*   Updated: 2025/08/25 18:16:24 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
    std::cout << "HumanB Constructor" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB Destructor" << std::endl;
}

void	HumanB::attack(void)
{
	if (_weapon == NULL)
	{
		std::cout << _name << " does not have a weapon" << std::endl;
		return ;
	}
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &club)
{
    _weapon = &club;
}
