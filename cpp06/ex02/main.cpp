/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:31:01 by pavicent          #+#    #+#             */
/*   Updated: 2026/01/20 09:31:03 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"

int main(void)
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; i++)
    {
        Base* obj = generate();

        std::cout << "Pointer: ";
        identify(obj);

        std::cout << "Reference: ";
        identify(*obj);

        std::cout << "----" << std::endl;
        delete obj;
    }
    return (0);
}
