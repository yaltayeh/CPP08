#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>

void testVector()
{
	std::cout << "\n===== Testing with std::vector: =====" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i * 10);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 50);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 55);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void testList()
{
	std::cout << "\n===== Testing with std::list: =====" << std::endl;
	std::list<int> lst;
	for (int i = 0; i < 10; ++i)
		lst.push_back(i * 15);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 45);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(lst, 50);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void testDeque()
{
	std::cout << "\n===== Testing with std::deque: =====" << std::endl;
	std::deque<int> deq;
	for (int i = 0; i < 10; ++i)
		deq.push_back(i * 20);

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 80);
		std::cout << "Found in deque: " << *it << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 85);
		std::cout << "Found in deque: " << *it << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	testVector();
	testList();
	testDeque();
	return 0;
}