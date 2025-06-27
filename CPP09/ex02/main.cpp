#include <iostream>
#include "PmergeMe.hpp"
#include <cstdlib>
#include <algorithm>
#include <unistd.h>
#include <climits>
#include <ctime>
#include <cerrno>

static bool check_args(char **argv);


int main(int argc, char **argv)
{
    if (argc < 2){
        std::cerr << "program arguments" << std::endl;
        return 1;
    }
    if (!check_args(argv + 1)){
        std::cerr << "argument must be only postive numbers (between 0 and INTMAX)" << std::endl;
        return 1;
    }



    {
        std::clock_t start = std::clock();
        std::vector<int> vec = vector_create(argv + 1);
        std::vector<int> vec_sorted = vector_sort(vec);
        std::clock_t end = std::clock();


        std::cout << "Before:" << vector_toString(vec) << std::endl;
        std::cout << "After: " << vector_toString(vec_sorted) << std::endl;
        std::cout << "vectors => " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    }

    {
        std::clock_t start = std::clock();
        std::deque<int> deq = deque_create(argv + 1);
        std::deque<int> deq_sorted = deque_sort(deq);
        std::clock_t end = std::clock();

        std::cout << "deque   => " << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    }
}

static bool check_args(char **str)
{
    for (int i = 0; str[i]; i++) {
        for (size_t j = 0; str[i][j]; j++)
            if (!std::isdigit(str[i][j])) return false;
        long val = std::strtol(str[i], 0, 10);
        if (errno != 0 || val < 0 || val > INT_MAX)
            return false;
    }
    return true;
}