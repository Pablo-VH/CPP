/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:11:50 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/15 19:11:53 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "CalpTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage;
		std::cout << " points of damage!" << std::endl;
		--this->_energyPoints;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " tries to attack " << target;
		if (this->_energyPoints <= 0 && this->_hitPoints > 0)
			std::cout << " but " << this->_name << " has no energy points!" << std::endl;
		else if (this->_hitPoints <= 0)
			std::cout << " but " << this->_name << " is dead!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount;
		std::cout << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints <= 0)
			std::cout << "ClapTrap " << this->_name << " has died!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " is repaired " << amount;
		std::cout << " hit points!" << std::endl;
		--this->_energyPoints;
		this->_hitPoints += amount;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " tries to repair itself ";
		if (this->_energyPoints < 0 && this->_hitPoints > 0)
			std::cout << "but has no energy points!" << std::endl;
		else if (this->_hitPoints < 0)
			std::cout << "but " << this->_name << " is dead!" << std::endl;
	}
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}
