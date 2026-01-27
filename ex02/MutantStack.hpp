#pragma once

#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
protected:
	using std::stack<T>::c; // 

public:
	MutantStack();
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();;
	iterator end();
};

#include "MutantStack.tpp"
