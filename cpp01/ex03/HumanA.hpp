/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:16:35 by pavicent          #+#    #+#             */
/*   Updated: 2025/08/25 18:16:38 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP_
#define HUMANA_HPP_

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon &_weapon;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);
	void	attack(void);
};

#endif