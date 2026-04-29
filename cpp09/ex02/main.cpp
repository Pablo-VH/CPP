#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe 1 3 5 2 4\n";
		return (1);
	}
	if (!initPmerge(argv))
		return (1);
}