/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:59:19 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 14:59:20 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== CREANDO ANIMALES ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    Cat cat2;


    std::cout << "\n=== TIPOS ===" << std::endl;
    std::cout << "Dog is of type: " << dog->getType() << std::endl;
    std::cout << "Cat is of type: " << cat->getType() << std::endl;
    std::cout << "Meta is of type: " << meta->getType() << std::endl;
    std::cout << "Cat2 is of type: " << cat2.getType() << std::endl;


    std::cout << "\n=== SONIDOS ===" << std::endl;
    cat->makeSound(); // debería hacer "meow"
    dog->makeSound(); // debería hacer "woof"
    meta->makeSound(); // sonido genérico
    cat2.makeSound();

    std::cout << "\n=== PROBANDO WRONGANIMAL ===" << std::endl;
    const WrongAnimal* wrong = new WrongCat();
    WrongCat    wcat;
    std::cout << "WrongAnimal is of type: " << wrong->getType() << std::endl;
    wrong->makeSound(); // ¡sonido de WrongAnimal, no de gato!
    std::cout << "WrongCat is of type: " << wcat.getType() << std::endl;
    wcat.makeSound();

    std::cout << "\n=== DESTRUYENDO ANIMALES ===" << std::endl;
    delete meta;
    delete dog;
    delete cat;
    delete wrong;

    std::cout << "\n=== FIN DEL PROGRAMA ===" << std::endl;
    return (0);
}
