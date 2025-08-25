/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:23:47 by pavicent          #+#    #+#             */
/*   Updated: 2025/08/25 18:23:48 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WRNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	int	filter;
	int	i;
	void (Harl:: *functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	i = 0;
	filter = -1;
	while (i < 4)
	{
		if (options[i] == level)
		{
			filter = i;
			break ;
		}
		i++;
	}
	switch (filter)
	{
		case 0:
			(this->*functions[i++])();
		case 1:
			(this->*functions[i++])();
		case 2:
			(this->*functions[i++])();
		case 3:
			(this->*functions[i++])();
			break ;
		default:
			std::cout << "Not a valid filter" << std::endl;
	}
	
}

Harl::Harl( void )
{
	std::cout << "Harl constructor" << std::endl;
}
Harl::~Harl( void )
{
	std::cout << "Harl destructor" << std::endl;
}
