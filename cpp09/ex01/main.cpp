#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments!\n";
		return (1);
	}
	if (!reversePolishNotation(argv[1]))
		return (1);
	return (0);
}