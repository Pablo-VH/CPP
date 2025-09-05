/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:04:42 by pavicent          #+#    #+#             */
/*   Updated: 2025/09/05 11:04:43 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
