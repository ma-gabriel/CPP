#include <iostream>
#include <sys/time.h>
#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <unistd.h>

static timeval get_time();
static bool check_args(char *argv);
static void diff_time(timeval start, timeval end, std::string prompt);


int main(int argc, char **argv)
{
    if (argc != 2){
        std::cerr << "program takes 1 argument" << std::endl;
        return 1;
    }
    if (!check_args(argv[1])){
        std::cerr << "argument must be only postive numbers (between 0 and INTMAX) and space" << std::endl;
        return 1;
    }



    timeval start = get_time();
    std::vector<int> vec = vector_create(argv[1]);
    std::vector<int> vec_sorted = vector_sort(vec);
    timeval end = get_time();


    std::cout << "Before:" << vector_toString(vec) << std::endl;
    std::cout << "After: " << vector_toString(vec_sorted) << std::endl;
    diff_time(start, end, "vectors => ");
}

static timeval get_time()
{
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv;
}

static void diff_time(timeval start, timeval end, std::string prompt = "")
{
    std::cout << prompt << \
    end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000 \
    << " seconds and " <<  (end.tv_usec - start.tv_usec) % 1000000 \
    << " microseconds" << std::endl;
    return ;
}

static bool check_args(char *str)
{
    for (size_t i = 0; str[i]; i++){
        if (str[i] == ' ')
            continue;
        if (!std::isdigit(str[i]))
            return false;
        if (std::atoi(str + i) < 0)
            return false;
    }
    return true;
}