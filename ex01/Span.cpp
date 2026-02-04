#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <numeric>

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

	std::vector<int> diffs(numbers.size());
	std::adjacent_difference(numbers.begin(), numbers.end(), diffs.begin());

	return *std::min_element(diffs.begin() + 1, diffs.end());
}

unsigned int Span::longestSpan() const
{
		if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	std::vector<int> diffs(numbers.size());
	std::adjacent_difference(numbers.begin(), numbers.end(), diffs.begin());

	return *std::max_element(diffs.begin() + 1, diffs.end());
}