#ifndef WRONGANIMAL_HPP_
#define WRONGANIMAL_HPP_

# include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal(void);
		
		std::string	getType() const;
		void	makeSound() const;
};

#endif