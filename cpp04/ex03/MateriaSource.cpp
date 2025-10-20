/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:53:47 by pavicent          #+#    #+#             */
/*   Updated: 2025/10/16 09:53:48 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		_templates[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _templates[i];
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = nullptr;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete _templates[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_templates[i])
		{
			_templates[i] = m;
			std::cout << "Learned materia " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	std::cout << "Unknown materia: " << type << std::endl;
	return (nullptr);
}