#pragma once

#include <iterator>
#include <vector>

template <class T, class Allocator = allocator<T>>
class MutantStack
{
	public:
		MutantStack(unsigned int N);
		MutantStack(MutantStack &ref);
		~MutantStack();
		MutantStack &operator=(MutantStack &ref);
		
	private:
		unsigned int _N;
		std::vector<int> _vec;
};
