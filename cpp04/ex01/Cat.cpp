#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor" << std::endl;
	*this = other;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->_type = other._type;
	}
	std::cout << "Cat copy assignment constructor" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow~" << std::endl;
}
