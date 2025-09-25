#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal(void);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal(void);
		std::string	getType() const;
		virtual void	makeSound() const;
};


#endif