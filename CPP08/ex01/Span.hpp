#pragma once

#include <vector>


class Span
{
	public:
		Span(unsigned int N);
		Span(Span &ref);
		~Span();
		Span &operator=(Span &ref);
		void addNumber(int n);
		int shortestSpan(void);
		int longestSpan(void);
		void addManyNumbers(unsigned int N);

	private:
		unsigned int _N;
		std::vector<int> _vec;
};
