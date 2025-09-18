/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:52:24 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/17 11:52:25 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default")
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string const& name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called for " << name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment constructor called" << std::endl;
	return(*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap 🤜🤛 wants a high five! Give me five!" << std::endl;
}
