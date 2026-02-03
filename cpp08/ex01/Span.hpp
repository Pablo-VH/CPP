#ifndef SPAN_HPP_
#define SPAN_HPP_

# include <iostream>
# include <vector>
# include <stdexcept>
# include <algorithm>

class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int n);
		
		template <typename InputIterator>
		void	addNumber(InputIterator begin, InputIterator end)
		{
			unsigned int rangeSize = std::distance(begin, end);
			if  (_numbers.size() + rangeSize > _maxSize)
				throw SpanFullException();
			_numbers.insert(_numbers.end(), begin, end);
		}

		int		shortestSpan() const;
		int		longestSpan() const;
		class SpanFullException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class SpanTooSmallException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif