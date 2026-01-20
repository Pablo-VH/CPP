/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:30:48 by pavicent          #+#    #+#             */
/*   Updated: 2026/01/20 09:30:50 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

# include <cstdint>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
