/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:01:56 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 15:01:57 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal default constructor" << std::endl;
	this->_type = "Defalut";
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	std::cout << "AAnimal copy constructor" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "AAnimal copy assignment constructor" << std::endl;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor" << std::endl;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "*Generic Aanimal sound*" << std::endl;
}

std::string	AAnimal::getType() const
{
	return(_type);
}

