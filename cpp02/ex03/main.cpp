/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:04:26 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/05 11:04:28 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) 
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point p1(2, 2);
    Point p2(5, 5);   // diagonal
    Point p3(0, 0);   // vértice
    Point p4(10, 5);  // fuera

    std::cout << bsp(a,b,c,p1) << std::endl; // 1
    std::cout << bsp(a,b,c,p2) << std::endl; // 0
    std::cout << bsp(a,b,c,p3) << std::endl; // 0
    std::cout << bsp(a,b,c,p4) << std::endl; // 0
}