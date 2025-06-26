

#include "PmergeMe.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

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