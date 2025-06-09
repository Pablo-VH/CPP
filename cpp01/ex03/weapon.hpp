#ifndef WEAPON_HPP_
# define WEAPON_HPP_

# include <iostream>


class weapon
{
private:
	std::string _type;
public:
	void	setType(const std::string &newType);
	const std::string &getType(const weapon &w);
	weapon(std::string type);
	~weapon();
};

weapon::weapon(std::string type)
{
	this->_type = type;
}

weapon::~weapon()
{
}


#endif