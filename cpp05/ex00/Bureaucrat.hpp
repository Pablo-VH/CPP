#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

# include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat(void);
		const std::string& getName(void) const;
		int getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

	std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif