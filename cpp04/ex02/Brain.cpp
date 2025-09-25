/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:03:26 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 15:03:27 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor" << std::endl;
	*this = other;
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain copy assignment constructor" << std::endl;
	return(*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor" << std::endl;
}

void	Brain::setIdea(int index, std::string& idea)
{
	this->_ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	return(this->_ideas[index]);
}
