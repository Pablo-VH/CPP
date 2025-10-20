/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:52:19 by pavicent          #+#    #+#             */
/*   Updated: 2025/10/16 09:52:21 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("unknown")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

std::string const & Character::getName() const
{ 
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (!m) return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << _name << " equips " << m->getType() << " in slot " << i << "\n";
			return ;
		}
	}
	std::cout << _name << "'s inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return ;
	std::cout << _name << " unequips " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
	_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
}