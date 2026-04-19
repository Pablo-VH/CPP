#ifndef UTILS_HPP_
#define UTILS_HPP_

# include "BitcoinExchange.hpp"

std::string rtrim(std::string& line);
std::string trim(std::string& line);
void		checkDate(std::string& date);
void		checkTop(std::string& line);
void		checkTopCsv(std::string& line);

#endif