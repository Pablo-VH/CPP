#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

# include <iostream>
# include <string>

class AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal(void);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal(void);
		std::string	getType() const;
		//void	setType(std::string type);
		virtual void	makeSound() const = 0;
};


#endif