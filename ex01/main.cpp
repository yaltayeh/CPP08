#include <iostream>
#include "Span.hpp"
#include <cstdlib>
#include <fstream>

void printResults(const Span &sp)
{
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
}

void test10_000()
{
	Span sp = Span(10000);

	srand(time(NULL));
	for (int i = 0; i < 10000; ++i)
		sp.addNumber(rand());

	printResults(sp);
}

void testUserInput(std::istream &in)
{
	Span sp = Span(10000);

	in >> std::ws;
	for (int i = 0; i < 10000; ++i)
	{
		int number;
		in >> number;
		if (in.fail() || in.eof())
			break;
		sp.addNumber(number);
		in >> std::ws;
	}

	printResults(sp);
}

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cerr << "Usage: " << argv[0] << " [input_file|- for stdin]" << std::endl;
		return 1;
	}
	if (argv[1])
	{
		if (std::string(argv[1]) == "-")
		{
			std::cout << "Enter numbers (separate by spaces), end with EOF (Ctrl+D):" << std::endl;
			testUserInput(std::cin);
			return 0;
		}
		std::ifstream file(argv[1]);
		if (!file)
		{
			std::cerr << "Could not open file: " << argv[1] << std::endl;
			return 1;
		}
		testUserInput(file);
		return 0;
	}
	else
	{
		// No arguments, run default test
		test10_000();
	}
}
