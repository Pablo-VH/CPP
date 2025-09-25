/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:00:45 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 15:00:46 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog assignment constructor" << std::endl;
	//*this = other;
	this->_type = other._type;
	this->brain = new Brain(*other.brain);
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->_type = other._type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Dog copy assignment constructor" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof! Woof!" << std::endl;
}

std::string	Dog::getIdea(int i) const
{
	return(this->brain->getIdea(i));
}

void	Dog::setIdea(int i, std::string idea)
{
	this->brain->setIdea(i, idea);
}
