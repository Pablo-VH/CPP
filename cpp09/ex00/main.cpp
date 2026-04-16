#include "BitcoinExchange.hpp"
#include <iostream>
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Bad input: ./btc filename\n";
		return (1);
	}
	BitcoinExchange	pg(argv[1]);
	return (0);
}