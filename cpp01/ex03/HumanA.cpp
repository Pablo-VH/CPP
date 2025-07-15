#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA Constructor" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA Destructor" << std::endl;
}