/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:03:18 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 15:03:20 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP_
#define WRONGANIMAL_HPP_

# include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal(void);

		std::string	getType() const;
		void	makeSound() const;
};

#endif
