#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor" << std::endl;
	this->_type = "Defalut";
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Animal copy constructor" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Animal copy assignment constructor" << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "*Generic animal sound*" << std::endl;
}

std::string	Animal::getType() const
{
	return(_type);
}
