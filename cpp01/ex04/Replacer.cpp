#include "Replacer.hpp"

Replacer::Replacer(const std::string &filename, const std::string &s1, const std::string &s2) : _s1(s1), _s2(s2), _filename(filename)
{
	std::cout << "Replacer constructor" << std::endl;
}

Replacer::~Replacer(void)
{
	std::cout << "Replacer destructor" << std::endl;
}


bool	Replacer::process()
{
	std::string		line;
	std::string		outfilename;
	outfilename = _filename + ".replace";
	std::ifstream	infile(_filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Cannot open input file." << std::endl;
		return (false);
	}
	std::ofstream	outfile(outfilename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Cannot open output file." << std::endl;
		return (false);
	}
	while (std::getline(infile, line))
	{
		outfile << Replacer::replaceAll(line);
		if (!infile.eof())
			outfile << '\n';
	}
	return (true);
}

std::string	Replacer::replaceAll(const std::string &line)
{
	std::string	result;
	size_t		pos;
	size_t		found;
	pos = 0;
	while ((found = line.find(_s1, pos)) != std::string::npos)
	{
		result += line.substr(pos, found - pos);
		result += _s2;
		pos = found + _s1.length();
	}
	result += line.substr(pos);
	return (result);
}
