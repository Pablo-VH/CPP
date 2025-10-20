/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:05:53 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/25 15:05:54 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main(void)
{
std::cout << "=== CREANDO MATERIA SOURCE ===" << std::endl;
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
src->learnMateria(new Ice());  // Repetida, debe seguir aprendiendo
src->learnMateria(new Cure());
src->learnMateria(new Ice());  // Esta debería ser ignorada (ya hay 4)

std::cout << "\n=== CREANDO PERSONAJES ===" << std::endl;
ICharacter* me = new Character("me");
ICharacter* bob = new Character("bob");

std::cout << "\n=== CREANDO Y EQUIPANDO MATERIAS ===" << std::endl;
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);

std::cout << "\nIntentando equipar una quinta materia (debe fallar):" << std::endl;
tmp = src->createMateria("ice");
me->equip(tmp); // No debería hacer nada

std::cout << "\n=== USANDO MATERIAS ===" << std::endl;
me->use(0, *bob);
me->use(1, *bob);
me->use(2, *bob);
me->use(3, *bob);
me->use(4, *bob); // fuera de rango, no debería pasar nada

std::cout << "\n=== PROBANDO UNEQUIP ===" << std::endl;
me->unequip(1); // debe liberar el slot pero no borrar la materia
me->use(1, *bob); // no debería hacer nada

std::cout << "\n=== PROBANDO COPIAS ===" << std::endl;
std::cout << "Creando copia de 'me' en 'clone'...\n";
Character clone(*(Character*)me);
std::cout << "Usando materias del clon sobre 'bob'...\n";
clone.use(0, *bob);
clone.use(2, *bob);

std::cout << "\nModificando una materia en el clon (deep copy check)..." << std::endl;
// (Aquí podrías comprobar direcciones de memoria o diferenciar materias si lo implementas)

std::cout << "\n=== BORRANDO PERSONAJES Y SOURCE ===" << std::endl;
delete bob;
delete me;
delete src;

std::cout << "\n=== FIN DEL PROGRAMA ===" << std::endl;
return 0;

}
