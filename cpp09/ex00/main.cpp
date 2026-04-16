#include "BitcoinExchange.hpp"
#include <iostream>
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Bad input: ./btc filename\n";
		return (1);
	}
	try{
	BitcoinExchange	pg(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}