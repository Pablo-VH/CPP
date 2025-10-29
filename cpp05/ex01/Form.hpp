/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:15:44 by pavicent          #+#    #+#             */
/*   Updated: 2025/10/29 19:15:45 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP_
#define FORM_HPP_

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		int					_gradeReqSign;
		int					_gradeReqExec;
	public:
		Form(void);
		Form(std::string name, int gradeReqSign, int gradeReqExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form(void);
		const std::string&	getName() const;
		bool				getSigned()const;
		int					getGradeSign() const;
		int					getGradeExec()const;
		void				beSigned(const Bureaucrat& b);
	class GradeTooHighException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif