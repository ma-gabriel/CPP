
#include "RPN.hpp"
#include <iostream>
#include <stack>

int main(int argc, char **argv)
{
    if (argc != 2){
        std::cerr << "program takes 1 argument" << std::endl;
        return 1;
    }

    try {
        std::cout << RPN::process(argv[1]) << std::endl;
    }
    catch (const char *e){
        std::cerr << e << std::endl;
        return 1;
    }
    return 0;
}