#ifndef FIXED_HPP_
#define FIXED_HPP_

# include <iostream>
class Fixed
{
	private:
		int					_value;
		static const int	_fbits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed(void);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};


#endif
