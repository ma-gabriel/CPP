#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2){
        std::cerr << "program takes 1 argument" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange tmp;
        tmp.process(argv[1]);
    }
    catch (std::string &e)
    {
        std::cerr << e << std::endl;
    }
}
