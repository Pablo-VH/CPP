#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

# include <map>
# include <fstream>
# include <iostream>
# include <sstream>
# include <algorithm>
# include <string>
# include <stdexcept>

class BitcoinExchange
{
private:
	//std::map<std::string, double>	_pair;
	std::string						_content;
	std::string						_key;
public:
	BitcoinExchange(void);
	BitcoinExchange(char *file);
	~BitcoinExchange(void);

};
class InvalidContentFile : public std::exception
{
	public:
		const char* what() const throw();
};

class InvalidDate : public std::exception
{
	public:
		const char* what() const throw();
};

void	tokenize(std::string& tokens);

#endif

/*Ejercicio 00: Bitcoin Exchange
Usa std::map<std::string, double>.
Motivo: necesitas buscar por fecha y, si no existe, tomar la fecha inmediatamente anterior. std::map te permite hacerlo de forma natural con búsqueda ordenada (lower_bound).

Ejercicio 01: RPN
Usa std::list<int> como pila manual (push_back/pop_back).
Motivo: RPN es comportamiento LIFO, y así evitas reutilizar el contenedor del ejercicio anterior.

Ejercicio 02: PmergeMe
Usa dos contenedores distintos: std::vector<int> y std::deque<int>.
Motivo: el enunciado pide al menos dos contenedores y comparar tiempos; ambos tienen acceso aleatorio, lo que facilita mucho Ford-Johnson y la medición de rendimiento.*/