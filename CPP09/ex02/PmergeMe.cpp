

#include "PmergeMe.hpp"

#include <string>
#include <vector>
#include <algorithm> // for std::swap
#include <iostream> // for std::cout
#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


std::vector<int> vector_create(char *arg)
{
    std::vector<int> res;
    std::stringstream s((std::string(arg)));

    while (s){
        int buff = -1;
        s >> buff;
        if (buff != -1)
            res.push_back(buff);
    }
    return res;
}

#define DEBUG

void vector_sort_algo(std::vector<int> &vec, size_t size=1)
{
	if (size >= vec.size()) {
#ifdef DEBUG
		std::cout << ":" << vector_toString(vec) << std::endl;
#endif
		return;
	}
	std::vector<int> A;
	std::vector<int>left;
	size_t i;
	for (i = 0; i  + size * 2 < vec.size(); i += size * 2){
		if (vec[i + size - 1] < vec[i + size * 2 - 1]){
			for (size_t j = 0; j < size; j++)
				A.push_back(vec[i + j]);
			for (size_t j = 0; j < size; j++)
				A.push_back(vec[i + size + j]);
		}
		else {
			for (size_t j = 0; j < size; j++)
				A.push_back(vec[i + size + j]);
			for (size_t j = 0; j < size; j++)
				A.push_back(vec[i + j]);
		}
	}
	for (;i < vec.size(); i++)
		left.push_back(vec[i]);
#ifdef DEBUG
	std::cout << ":" << vector_toString(A) << vector_toString(left) << std::endl;
#endif
	vector_sort_algo(A, size * 2);

	std::vector<int> res;
        std::vector<int> small;
        std::vector<int> big;
	for (size_t i = 0; i  + size * 2 < vec.size(); i += size * 2){
		for (size_t j = 0; j < size; j ++)
			small.push_back(A[i + j]);
		for (size_t j = 0; j < size; j ++)
			big.push_back(A[i + size + j]);
	}
	for (std::vector<int>::iterator it = left.begin(); it != left.end(); it++)
		small.push_back(*it);
	for (size_t i = 0; i < size; i++){
		big.insert(big.begin()+i);
		small.erase(begin());
	}
	while (small.size())
	{
#ifdef DEBUG
		std::cout << "big:" << vector_toString(big) << "\nsmall:" << vector_toString(small) << std::endl;
#endif
	}

}

#undef DEBUG


std::vector<int> vector_sort(std::vector<int> vec) {
    vector_sort_algo(vec);
    return vec;
}


std::string vector_toString(std::vector<int> &vec)
{
    std::string str;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        str += SSTR(" " << *it);
    return str;
}
