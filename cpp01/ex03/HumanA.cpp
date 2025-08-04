#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA Constructor" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA Destructor" << std::endl;
}

void	HumanA::attack(void)
{
	 std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}