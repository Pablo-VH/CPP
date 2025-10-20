/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:52:27 by pavicent          #+#    #+#             */
/*   Updated: 2025/10/16 09:52:29 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];
	public:
		Character(void);
		Character(std::string const& name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character(void);

		std::string const& getName()const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif