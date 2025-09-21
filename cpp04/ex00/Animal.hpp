#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

# include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		~Animal(void);
};


#endif