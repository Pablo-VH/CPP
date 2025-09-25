/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:57:48 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 14:57:54 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal(void);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal(void);
		std::string	getType() const;
		virtual void	makeSound() const;
};


#endif
