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

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    std::list<int>   l;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i * 2);
        l.push_back(i);
    }

    try
    {
        std::cout << "Vector test:\n";
        std::vector<int>::iterator it = easyfind(v, 6);
        std::cout << "Found: " << *it << std::endl;

        std::cout << "List test:\n";
        std::list<int>::iterator it2 = easyfind(l, 5);
        std::cout << "Found: " << *it2 << std::endl;

        std::cout << "Fail test:\n";
        easyfind(v, 42);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
