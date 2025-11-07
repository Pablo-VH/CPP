/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:26:53 by pavicent          #+#    #+#             */
/*   Updated: 2025/11/07 11:26:55 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm created for target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45), _target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm copy assignment constructor" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->checkExecutability(executor);
	//std::srand(std::time(NULL));
	int	success = std::rand() % 2;
	if (success)
		std::cout << this->_target << " has been robotomized successfully 🤖" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->_target << std::endl;
}
