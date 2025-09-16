#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	FragTrap(void);
	FragTrap(std::string const& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap(void);
	void	highFivesGuys(void);
};

#endif