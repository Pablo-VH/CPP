/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:14:56 by pavicent          #+#    #+#             */
/*   Updated: 2025/10/29 19:14:57 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    std::cout << "=== Testing Intern makeForm() (no assumptions about AForm internals) ===\n\n";

    Intern intern;
    AForm* form = NULL;

    // Test 1
    std::cout << "[1] Requesting 'shrubbery creation'...\n";
    form = intern.makeForm("shrubbery creation", "Home");
    if (form)
    {
        std::cout << " -> makeForm returned a non-null pointer. (OK)\n";
        delete form;
    }
    else
        std::cout << " -> makeForm returned nullptr. (FAIL)\n";

    std::cout << '\n';

    // Test 2
    std::cout << "[2] Requesting 'robotomy request'...\n";
    form = intern.makeForm("robotomy request", "Bender");
    if (form)
    {
        std::cout << " -> makeForm returned a non-null pointer. (OK)\n";
        delete form;
    }
    else
        std::cout << " -> makeForm returned nullptr. (FAIL)\n";

    std::cout << '\n';

    // Test 3
    std::cout << "[3] Requesting 'presidential pardon'...\n";
    form = intern.makeForm("presidential pardon", "Arthur Dent");
    if (form)
    {
        std::cout << " -> makeForm returned a non-null pointer. (OK)\n";
        delete form;
    }
    else
        std::cout << " -> makeForm returned nullptr. (FAIL)\n";

    std::cout << '\n';

    // Test 4: invalid
    std::cout << "[4] Requesting 'coffee request' (invalid)...\n";
    form = intern.makeForm("coffee request", "Intern");
    if (form)
    {
        std::cout << " -> Unexpected: makeForm returned a pointer for an invalid name. Deleting it.\n";
        delete form;
    }
    else
        std::cout << " -> makeForm returned nullptr as expected for invalid name.\n";

    std::cout << "\n=== Done ===\n";
    return (0);
}