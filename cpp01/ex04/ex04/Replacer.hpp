#pragma once

# include <iostream>
# include <fstream>

class Replacer
{
	private:
		std::string	_s1;
		std::string	_s2;
		std::string	_filename;

		std::string	replaceAll(const std::string &line);
	public:
		Replacer(const std::string &filename, const std::string &s1, const std::string &s2);
		bool process(void);
		~Replacer(void);
};

