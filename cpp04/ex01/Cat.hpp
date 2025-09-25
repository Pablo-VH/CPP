#ifndef CAT_HPP_
#define CAT_HPP_

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* brain;
	public:
		Cat(void);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat(void);

		void	makeSound(void) const;
		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i) const;
};

#endif