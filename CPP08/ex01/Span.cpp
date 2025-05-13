
#include "Span.hpp"
#include <iostream>
#include <algorithm>


Span::Span(unsigned int N)
{
	_N = N;
}

Span::Span(Span &ref)
{
	_N = ref._N;
}

Span::~Span()
{}


Span &Span::operator=(Span &ref)
{
	_N = ref._N;
	_vec = ref._vec;
	return *this;
}

void Span::addNumber(int n)
{
	if (_vec.size() >= _N)
    	throw std::out_of_range("Too much Values");
	_vec.push_back(n);
}

int Span::shortestSpan(void)
{
	if (_vec.size() <= 1)
		throw std::out_of_range("Not enough Values");
	int res = std::abs(_vec[0] - _vec[1]);
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 0; i < _vec.size() - 1; i++)
		if (tmp[i + 1] - tmp[i] < res)
			res = tmp[i + 1] - tmp[i];
	return res;
	
}

int Span::longestSpan(void)
{
	if (_vec.size() <= 1)
		throw std::out_of_range("Not enough Values");
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}


void Span::addManyNumbers(std::vector<int>::iterator start, std::vector<int>::iterator ending)
{
	if (_vec.size() + ending - start > _N)
    	throw std::out_of_range("Too much Values");
	_vec.insert(_vec.end(), start, ending);
}