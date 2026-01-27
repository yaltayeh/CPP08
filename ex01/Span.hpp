#pragma once

#include <set>

class Span
{
private:
	const unsigned int max_size;
	std::multiset<int> numbers;

public:
	Span(unsigned int max_size);
	~Span();

	template <typename T>
	void addNumber(T &container);

	template <typename T>
	void addNumber(T iterator_begin, T iterator_end);

	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

template <typename T>
void Span::addNumber(T &container)
{
	if (container.size() + numbers.size() > max_size)
		throw std::out_of_range("Span is already full");
	typename T::iterator it = container.begin();
	for (; it != container.end(); ++it)
		numbers.insert(*it);
}

template <typename T>
void Span::addNumber(T iterator_begin, T iterator_end)
{
	size_t distance = std::distance(iterator_begin, iterator_end);
	if (distance + numbers.size() > max_size)
		throw std::out_of_range("Span is already full");
	for (T it = iterator_begin; it != iterator_end; ++it)
		numbers.insert(*it);
}
