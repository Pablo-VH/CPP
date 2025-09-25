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

    std::cout << "\n=== TIPOS ===" << std::endl;
    std::cout << "Dog is of type: " << dog->getType() << std::endl;
    std::cout << "Cat is of type: " << cat->getType() << std::endl;
    std::cout << "Meta is of type: " << meta->getType() << std::endl;

    std::cout << "\n=== SONIDOS ===" << std::endl;
    cat->makeSound(); // debería hacer "meow"
    dog->makeSound(); // debería hacer "woof"
    meta->makeSound(); // sonido genérico

    std::cout << "\n=== PROBANDO WRONGANIMAL ===" << std::endl;
    const WrongAnimal* wrong = new WrongCat();
    std::cout << "WrongCat is of type: " << wrong->getType() << std::endl;
    wrong->makeSound(); // ¡sonido de WrongAnimal, no de gato!

    std::cout << "\n=== DESTRUYENDO ANIMALES ===" << std::endl;
    delete meta;
    delete dog;
    delete cat;
    delete wrong;

    std::cout << "\n=== FIN DEL PROGRAMA ===" << std::endl;
    return 0;
}