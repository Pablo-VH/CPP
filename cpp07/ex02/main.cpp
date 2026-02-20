/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:35:10 by pavicent          #+#    #+#             */
/*   Updated: 2026/01/27 09:35:11 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    try
    {
        std::cout << "===== INT TEST =====" << std::endl;
        Array<int> a(5);

        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i * 10;

        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << std::endl;


        std::cout << "\n===== CHAR TEST =====" << std::endl;
        Array<char> c(4);

        c[0] = 'H';
        c[1] = 'o';
        c[2] = 'l';
        c[3] = 'a';

        for (unsigned int i = 0; i < c.size(); i++)
            std::cout << c[i] << std::endl;


        std::cout << "\n===== DOUBLE TEST =====" << std::endl;
        Array<double> d(3);

        d[0] = 3.14;
        d[1] = 2.71;
        d[2] = 42.0;

        for (unsigned int i = 0; i < d.size(); i++)
            std::cout << d[i] << std::endl;


        std::cout << "\n===== FLOAT TEST =====" << std::endl;
        Array<float> f(3);

        f[0] = 1.1f;
        f[1] = 2.2f;
        f[2] = 3.3f;

        for (unsigned int i = 0; i < f.size(); i++)
            std::cout << f[i] << std::endl;


        std::cout << "\n===== STRING TEST =====" << std::endl;
        Array<std::string> s(3);

        s[0] = "hola";
        s[1] = "que";
        s[2] = "tal";

        for (unsigned int i = 0; i < s.size(); i++)
            std::cout << s[i] << std::endl;


        std::cout << "\n===== BOOL TEST =====" << std::endl;
        Array<bool> b(3);

        b[0] = true;
        b[1] = false;
        b[2] = true;

        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << std::endl;


        std::cout << "\n===== COPY TEST =====" << std::endl;
        Array<int> copy = a;
        copy[0] = 999;

        std::cout << "Original a:" << std::endl;
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << std::endl;

        std::cout << "Copy:" << std::endl;
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << std::endl;


        std::cout << "\n===== ASSIGNMENT TEST =====" << std::endl;
        Array<int> assign;
        assign = a;
        assign[1] = 555;

        std::cout << "Original a:" << std::endl;
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << std::endl;

        std::cout << "Assigned:" << std::endl;
        for (unsigned int i = 0; i < assign.size(); i++)
            std::cout << assign[i] << std::endl;


        std::cout << "\n===== SIZE 0 TEST =====" << std::endl;
        Array<int> empty;
        std::cout << "Size: " << empty.size() << std::endl;


        std::cout << "\n===== OUT OF BOUNDS TEST =====" << std::endl;
        std::cout << a[42] << std::endl; // debe lanzar excepción
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
