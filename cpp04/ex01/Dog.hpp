#ifndef DOG_HPP_
#define DOG_HPP_

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
	Brain* brain;
	public:
		Dog(void);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog(void);

		void	makeSound(void) const;
};

#endif