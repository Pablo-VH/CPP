#include "Span.hpp"

Span::Span()
{}

Span::Span(unsigned int N) : _maxSize(N)
{}

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize)
{}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_numbers = other._numbers;
		this->_maxSize = other._maxSize;
	}
	return (*this);
}

Span::~Span(void)
{}

void	Span::addNumber(int n)
{
	if (this->_numbers.size() >= this->_maxSize)
	 	throw SpanFullException();
	_numbers.push_back(n);
}

int	Span::longestSpan() const
{
	if (this->_numbers.size() <= 1)
		throw SpanTooSmallException();
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int	max = *std::max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}

int	Span::shortestSpan() const
{
	int	minSpan;
	int	diff;
	size_t	i = 1;
	if (this->_numbers.size() <= 1)
		throw SpanTooSmallException();
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	minSpan = sorted[1] - sorted[0];
	while (i < sorted.size())
	{
		diff = sorted[i] - sorted[i - 1];
		if (diff < minSpan)
			minSpan = diff;
		i++;
	}
	return (minSpan);
}

const char*	Span::SpanFullException::what() const throw()
{
	return ("Span is full!");
}

const char*	Span::SpanTooSmallException::what() const throw()
{
	return ("Not enough numbers to find a span!");
}
