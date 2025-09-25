#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	std::cout << "Cat copy constructor" << std::endl;
	//*this = other;
	this->_type = other._type;
	this->brain = new Brain(*other.brain);
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		this->_type = other._type;
		delete (this->brain);
		this->brain = new Brain(*other.brain);
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

std::string	Cat::getIdea(int i) const
{
	return(this->brain->getIdea(i));
}

void	Cat::setIdea(int i, std::string idea)
{
	this->brain->setIdea(i, idea);
}