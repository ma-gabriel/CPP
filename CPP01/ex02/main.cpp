//#include "Zombie.hpp"
#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";

    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "&string:    " << &string << "\n";
    std::cout << " stringPTR: " << stringPTR << "\n";
    std::cout << "&stringREF: " << &stringREF << "\n";

    std::cout << "\n";

    std::cout << " string:    " << string << "\n";
    std::cout << "*stringPTR: " << *stringPTR << "\n";
    std::cout << " stringREF: " << stringREF << "\n";
}