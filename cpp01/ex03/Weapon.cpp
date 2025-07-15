#include "Weapon.hpp"

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
const	std::string& Weapon::getType(void)
{
	return(this->_type);
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Weapon constructor" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon destructor" << std::endl;
}