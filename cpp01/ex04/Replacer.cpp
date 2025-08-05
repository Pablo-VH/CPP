#include "Replacer.hpp"

Replacer::Replacer(const std::string &filename, const std::string &s1, const std::string &s2) : _filename(filename), _s1(s1), _s2(s2)
{
	std::cout << "Replacer constructor" << std::endl;
}

Replacer::~Replacer(void)
{
	std::cout << "Replacer destructor" << std::endl;
}

bool	Replacer::process()
{
	std::ifstream	infile(_filename);
	if (!infile.is_open())
	{
		std::cerr << "Error: Cannot open input file." << std::endl;
		return (false);
	}
	std::ofstream	outfile(_filename + ".replace");
	if (outfile.is_open())
	{
		std::cerr << "Error: Cannot open output file." << std::endl;
		return (false);
	}
}