#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor" << std::endl;
	this->_type = "Defalut";
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor" << std::endl;
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

void	Animal::makeSound(void)
{
	std::cout << "This animal is a " << this->_type << " and sais: ";
	if (this->_type == "Dog")
	{
		std::cout << "Guau!" << std::endl;
	}
	else if (this->_type == "Cat")
	{
		std::cout << "Miau!" << std::endl;
	}
}

void	Animal::getType()
{
	std::cout << "Is a " << this->_type;
}