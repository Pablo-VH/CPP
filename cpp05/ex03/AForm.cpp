/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:15:39 by pavicent          #+#    #+#             */
/*   Updated: 2025/11/07 11:25:08 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Default"), _signed(false), _gradeReqSign(150), _gradeReqExec(150)
{
	std::cout << "Default AForm constructor" << std::endl;
}

AForm::AForm(std::string name, int gradeReqSign, int gradeReqExec) : _name(name), _signed(false), _gradeReqSign(gradeReqSign), _gradeReqExec(gradeReqExec)
{
	std::cout << "Assignment AForm constructor" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeReqSign(other._gradeReqSign), _gradeReqExec(other._gradeReqExec)
{
	std::cout << "Copy AForm constructor" << std::endl;
}

AForm&	AForm::operator=(const AForm& other)
{
	std::cout << "Copy assignment AForm constructor" << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
		this->_gradeReqSign = other._gradeReqSign;
		this->_gradeReqExec = other._gradeReqExec;
	}
	return(*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor" << std::endl;
}

const std::string&	AForm::getName(void)const
{
	return(this->_name);
}

bool	AForm::getSigned(void) const
{
	return(this->_signed);
}

const int&	AForm::getGradeSign(void) const
{
	return(this->_gradeReqSign);
}

const int&	AForm::getGradeExec(void) const
{
	return(this->_gradeReqExec);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return("the grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("the grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return("the form is not signed");
}

const char* AForm::IsSignedException::what() const throw()
{
	return("the form is signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "Form \"" << f.getName() << "\""
		<< " [sign grade: " << f.getGradeSign()
		<< ", exec grade: " << f.getGradeExec()
		<< ", signed: "; 
		if (f.getSigned())
			os << "yes";
		else
			os << "no";
		os << "]";
	return (os);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void	AForm::checkExecutability(const Bureaucrat& executor) const
{
	if (!this->getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
}
