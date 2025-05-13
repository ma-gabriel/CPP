

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

int main()
{
	std::srand(time(NULL));

	Span s(1000000); // 1 MILLION DE VALEURS !!!


	std::srand(time(NULL));
	std::vector <int> temp(1000000, 0);
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); ++it)
  		*it = std::rand();
	
	s.addManyNumbers(temp.begin(), temp.end());

	Span p(3);
	p.addNumber(10);
	p.addNumber(25);
	p.addNumber(800);
	//p.addNumber(12); //ex terminate called after throwing an instance of 'std::out_of_range'

	std::cout << s.longestSpan() << std::endl;	// complexite est celle d'un quicksort
	std::cout << s.shortestSpan() << std::endl;	// complexite est celle d'un quicksort
	std::cout << p.longestSpan() << std::endl;	// complexite est celle d'un quicksort
	std::cout << p.shortestSpan() << std::endl;	// complexite est celle d'un quicksort
	return 0;
}