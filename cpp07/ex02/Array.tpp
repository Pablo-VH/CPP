/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:35:32 by pavicent          #+#    #+#             */
/*   Updated: 2026/01/27 09:35:33 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP_
#define ARRAY_TPP_

//# include "Array.hpp" //ELIMINAR

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n)
{}

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(other._size)
{
	if (_size > 0)
	{
		unsigned int	i = 0;
		_data = new T[_size];
		while (i < _size)
		{
			_data[i] = other._data[i];
			i++;
		}
		
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		unsigned int	i = 0;
		delete[] _data;
		_size = other.size;
		if (_size > 0)
			_data = new T[_size];
		else
			_data = NULL;
		while (i < _size)
		{
			_data[i] = other._data[i];
			i++;
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return (_data[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return (_data[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

#endif
