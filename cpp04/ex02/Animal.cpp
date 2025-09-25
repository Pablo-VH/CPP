#include "Animal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal default constructor" << std::endl;
	this->_type = "Defalut";
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	std::cout << "AAnimal copy constructor" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "AAnimal copy assignment constructor" << std::endl;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor" << std::endl;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "*Generic Aanimal sound*" << std::endl;
}

std::string	AAnimal::getType() const
{
	return(_type);
}

