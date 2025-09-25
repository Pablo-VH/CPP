/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:01:08 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 15:01:09 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    std::cout << "=== CREANDO ANIMALES INDIVIDUALES ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n=== BORRANDO ANIMALES INDIVIDUALES ===" << std::endl;
    delete j; // no debe dar fugas de memoria
    delete i;

    std::cout << "\n=== ARRAY DE ANIMALES ===" << std::endl;
    const int size = 4;
    Animal* animals[size];

    // mitad perros, mitad gatos
    for (int k = 0; k < size; k++) {
        if (k < size / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    std::cout << "\n=== BORRANDO ARRAY DE ANIMALES ===" << std::endl;
    for (int k = 0; k < size; k++)
        delete animals[k];

    std::cout << "\n=== PROBANDO DEEP COPY EN DOG ===" << std::endl;
    Dog basic;
    basic.setIdea(0, "Chase the ball");
    basic.setIdea(1, "Eat kibble");

    Dog tmp = basic; // copy constructor
    std::cout << "Original idea[0]: " << basic.getIdea(0) << std::endl;
    std::cout << "Copied idea[0]  : " << tmp.getIdea(0) << std::endl;

    // modifico el copiado para ver si cambia el original
    tmp.setIdea(0, "Sleep all day");
    std::cout << "After modification:" << std::endl;
    std::cout << "Original idea[0]: " << basic.getIdea(0) << std::endl;
    std::cout << "Copied idea[0]  : " << tmp.getIdea(0) << std::endl;

    std::cout << "\n=== PROBANDO DEEP COPY EN CAT ===" << std::endl;
    Cat kitty;
    kitty.setIdea(0, "Climb the curtains");

    Cat kittyCopy;
    kittyCopy = kitty; // operator=
    std::cout << "Original idea[0]: " << kitty.getIdea(0) << std::endl;
    std::cout << "Copied idea[0]  : " << kittyCopy.getIdea(0) << std::endl;

    kittyCopy.setIdea(0, "Sleep on the keyboard");
    std::cout << "After modification:" << std::endl;
    std::cout << "Original idea[0]: " << kitty.getIdea(0) << std::endl;
    std::cout << "Copied idea[0]  : " << kittyCopy.getIdea(0) << std::endl;

    std::cout << "\n=== FIN DEL PROGRAMA ===" << std::endl;
    return (0);
}
