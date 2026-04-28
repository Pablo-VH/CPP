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
	BitcoinExchange	pg;
	std::cout << "_inputFile\n";
	/*for (std::multimap<std::string, double>::iterator it = pg.getInput().begin(); it != pg.getInput().end(); ++it)
		std::cout << "Date: " << it->first << " Amount: " << it->second << std::endl;
	std::cout << "\n_csv:\n";
	for (std::map<std::string, double>::iterator it = pg.getCsv().begin(); it != pg.getCsv().end(); ++it)
		std::cout << "Date: " << it->first << " Amount: " << it->second << std::endl;
	}*/
		pg.calculate(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}