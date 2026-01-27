#include "Span.hpp"

Span::Span(unsigned int max_size)
	: max_size(max_size), numbers()
{
	
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (numbers.size() >= max_size)
		throw std::runtime_error("Span is full");
	numbers.insert(number);
}

unsigned int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	unsigned int shortest = UINT_MAX;
	std::set<int>::const_iterator it = numbers.begin();
	std::set<int>::const_iterator next_it = std::next(it);

	while (next_it != numbers.end())
	{
		unsigned int span = *next_it - *it;
		if (span < shortest)
			shortest = span;
		++it;
		++next_it;
	}
	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	return *numbers.rbegin() - *numbers.begin();
}