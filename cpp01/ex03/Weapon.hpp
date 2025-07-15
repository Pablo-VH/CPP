#pragma once

# include <iostream>


class Weapon
{
private:
	std::string _type;
public:
	void	setType(std::string type);
	const std::string &getType(void);
	Weapon(std::string type);
	~Weapon();
};
