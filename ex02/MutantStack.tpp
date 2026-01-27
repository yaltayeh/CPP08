#include "MutantStack.hpp"

template <typename T>
inline MutantStack<T>::MutantStack()
{
}

template <typename T>
inline MutantStack<T>::~MutantStack()
{
}

template <typename T>
inline typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
inline typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}
