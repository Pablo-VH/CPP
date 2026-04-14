#ifndef MUTANTSTACK_TPP_
#define MUTANTSTACK_TPP_
//# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	std::stack<T>::operator=(other);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return this->c.end();
}

#endif