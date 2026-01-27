#ifndef EASYFIND_HPP_
#define EASYFIND_HPP_

# include <iostream>
# include <algorithm>
# include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int value);

# include "easyfind.tpp"

#endif