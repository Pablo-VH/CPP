#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== PROBANDO CLASES ABSTRACTAS ===" << std::endl;

    // Esto ya no compila, porque Animal es abstracta:
    //AAnimal a; // ❌ ERROR

    std::cout << "\n=== CREANDO ANIMALES ===" << std::endl;
    AAnimal* dog1 = new Dog();
    AAnimal* cat1 = new Cat();

    std::cout << "\n=== TIPOS Y SONIDOS ===" << std::endl;
    std::cout << "dog1 type: " << dog1->getType() << " -> ";
    dog1->makeSound();

    std::cout << "cat1 type: " << cat1->getType() << " -> ";
    cat1->makeSound();

    std::cout << "\n=== PROBANDO COPY CONSTRUCTOR ===" << std::endl;
    Dog* dog2 = new Dog(*(dynamic_cast<Dog*>(dog1)));  // copy constructor
    std::cout << "dog2 type: " << dog2->getType() << " -> ";
    dog2->makeSound();

    Cat cat2(*(dynamic_cast<Cat*>(cat1))); // copia en stack
    std::cout << "cat2 type: " << cat2.getType() << " -> ";
    cat2.makeSound();

    std::cout << "\n=== PROBANDO COPY ASSIGNMENT ===" << std::endl;
    Dog dog3;
    dog3 = *(dynamic_cast<Dog*>(dog1));  // copy assignment
    std::cout << "dog3 type: " << dog3.getType() << " -> ";
    dog3.makeSound();

    Cat cat3;
    cat3 = cat2;  // copy assignment en stack
    std::cout << "cat3 type: " << cat3.getType() << " -> ";
    cat3.makeSound();

    std::cout << "\n=== BORRANDO ANIMALES DINAMICOS ===" << std::endl;
    delete dog1;
    delete cat1;
    delete dog2;

    std::cout << "\n=== FIN DEL PROGRAMA ===" << std::endl;
    return (0);
}
