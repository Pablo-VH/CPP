/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:16:11 by pavicent          #+#    #+#             */
/*   Updated: 2025/08/25 18:16:15 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA Constructor" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA Destructor" << std::endl;
}

void	HumanA::attack(void)
{
	 std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
