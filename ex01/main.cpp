#include <iostream>
#include "Span.hpp"
#include <cstdlib>

int main()
{
	int arr[] = {5, 3, -1, -2, 17, 9, 11};

	Span sp = Span(10000 + sizeof(arr) / sizeof(arr[0]));
	
	sp.addNumber(arr, arr + sizeof(arr) / sizeof(arr[0]));

	srand(time(0));
	for (int i = 0; i < 10000; ++i)
		sp.addNumber(rand());

	try
	{
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
