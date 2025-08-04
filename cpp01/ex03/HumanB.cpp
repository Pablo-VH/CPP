#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
    std::cout << "HumanB Constructor" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB Destructor" << std::endl;
}

void	HumanB::attack(void)
{
	if (_weapon == NULL)
	{
		std::cout << _name << " does not have a weapon" << std::endl;
		return ;
	}
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &club)
{
    _weapon = &club;
}
