/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:45:57 by pavicent          #+#    #+#             */
/*   Updated: 2025/11/10 16:46:00 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other; return *this;
}

Intern::~Intern()
{
}

static AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    struct FormPair
    {
        const char* name;
        AForm* (*creator)(const std::string& target);
    };

    static const FormPair forms[] = {
        { "shrubbery creation",  &createShrubbery },
        { "robotomy request",    &createRobotomy },
        { "presidential pardon", &createPresidential }
    };

    const size_t numForms = sizeof(forms) / sizeof(forms[0]);

    for (size_t i = 0; i < numForms; ++i)
    {
        if (formName == forms[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (forms[i].creator(target));
        }
    }

    std::cerr << "Error: Form name \"" << formName << "\" not recognized." << std::endl;
    return NULL;
}
