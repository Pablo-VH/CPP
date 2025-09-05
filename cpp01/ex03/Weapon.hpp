/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:16:55 by pavicent          #+#    #+#             */
/*   Updated: 2025/08/25 18:16:57 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP_
#define WEAPON_HPP_

# include <iostream>

class Weapon
{
private:
	std::string _type;
public:
	void	setType(std::string type);
	const std::string &getType(void);
	Weapon(std::string type);
	~Weapon();
};

#endif