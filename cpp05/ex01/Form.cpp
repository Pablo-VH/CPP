/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:15:39 by pavicent          #+#    #+#             */
/*   Updated: 2025/10/29 19:15:40 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Default"), _signed(false), _gradeReqSign(150), _gradeReqExec(150)
{
	std::cout << "Default Form constructor" << std::endl;
}

Form::Form(std::string name, int gradeReqSign, int gradeReqExec) : _name(name), _signed(false), _gradeReqSign(gradeReqSign), _gradeReqExec(gradeReqExec)
{
	std::cout << "Assignment Form constructor" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeReqSign(other._gradeReqSign), _gradeReqExec(other._gradeReqExec)
{
	std::cout << "Copy Form constructor" << std::endl;
}

Form&	Form::operator=(const Form& other)
{
	std::cout << "Copy assignment Form constructor" << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return(*this);
}

Form::~Form(void)
{
	std::cout << "Form destructor" << std::endl;
}

const std::string&	Form::getName(void)const
{
	return(this->_name);
}

bool	Form::getSigned(void) const
{
	return(this->_signed);
}

const int	Form::getGradeSign(void) const
{
	return(this->_gradeReqSign);
}

const int	Form::getGradeExec(void) const
{
	return(this->_gradeReqExec);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return("the grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("the grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName();
	if (f.getSigned())
		os << " is";
	else
		os << " is not";
	os << " signed. Grade required to sign it: " << f.getGradeSign()
		<< ". Grade required to execute it: " << f.getGradeExec() << std::endl;
	return (os);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	this->_signed = true;
}