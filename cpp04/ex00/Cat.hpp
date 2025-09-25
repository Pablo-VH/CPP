/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:59:03 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 14:59:04 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP_
#define CAT_HPP_

# include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat(void);
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat(void);

	void	makeSound(void) const;
};

#endif
