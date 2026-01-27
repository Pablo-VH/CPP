/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:15:44 by pavicent          #+#    #+#             */
/*   Updated: 2025/11/07 11:25:16 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP_
#define AFORM_HPP_

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int					_gradeReqSign;
		const int					_gradeReqExec;
	public:
		AForm(void);
		AForm(std::string name, int gradeReqSign, int gradeReqExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm(void);
		const std::string&	getName() const;
		bool				getSigned()const;
		const int					getGradeSign() const;
		const int					getGradeExec()const;
		void				beSigned(const Bureaucrat& b);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		void				checkExecutability(const Bureaucrat& executor)const;
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
	class FormNotSignedException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
