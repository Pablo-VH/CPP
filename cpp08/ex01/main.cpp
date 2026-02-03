/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:51:15 by pavicent          #+#    #+#             */
/*   Updated: 2026/02/02 09:51:45 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Rango de números
        std::vector<int> moreNumbers;
        for (int i = 20; i < 25; ++i)
            moreNumbers.push_back(i);

        Span sp2(10);
        sp2.addNumber(1);
        sp2.addNumber(5);
        sp2.addNumber(moreNumbers.begin(), moreNumbers.end());

        std::cout << "Shortest span in sp2: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span in sp2: " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
