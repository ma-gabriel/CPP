#include <iostream>
#include <sys/time.h>
#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <unistd.h>

static timeval get_time();
static bool check_args(char **argv);
static void diff_time(timeval start, timeval end, std::string prompt);


int main(int argc, char **argv)
{
    if (argc < 2){
        std::cerr << "program arguments" << std::endl;
        return 1;
    }
    if (!check_args(argv + 1)){
        std::cerr << "argument must be only postive numbers (between 0 and INTMAX) and space" << std::endl;
        return 1;
    }



    {
        timeval start = get_time();
        std::vector<int> vec = vector_create(argv + 1);
        std::vector<int> vec_sorted = vector_sort(vec);
        timeval end = get_time();


        std::cout << "Before:" << vector_toString(vec) << std::endl;
        std::cout << "After: " << vector_toString(vec_sorted) << std::endl;
        diff_time(start, end, "vectors => ");
    }

    {
        timeval start = get_time();
        std::deque<int> deq = deque_create(argv + 1);
        std::deque<int> deq_sorted = deque_sort(deq);
        timeval end = get_time();


        std::cout << "Before:" << deque_toString(deq) << std::endl;
        std::cout << "After: " << deque_toString(deq_sorted) << std::endl;
        diff_time(start, end, "deques => ");
    }
}

static timeval get_time()
{
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv;
}

static void diff_time(timeval start, timeval end, std::string prompt = "")
{
    time_t seconds = end.tv_sec - start.tv_sec;
    suseconds_t microseconds = end.tv_usec - start.tv_usec;
    if (microseconds < 0) {
        seconds -= 1;
        microseconds += 1000000;
    }
    std::cout << prompt << seconds << " seconds and " << microseconds << " microseconds" << std::endl;

}

static bool check_args(char **str)
{
    for (int i = 0; str[i]; i++)
        for (size_t j = 0; str[i][j]; j++)
            if (!std::isdigit(str[i][j]))
                return false;
    return true;
}