#ifndef BRAIN_HPP_
#define BRAIN_HPP_

# include <iostream>

class Brain
{
	protected:
		std::string	ideas[100];
	public:
		Brain(void);
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain(void);

		void	setIdea(int index, std::string& idea);
		std::string getIdea(int index) const;
};

#endif