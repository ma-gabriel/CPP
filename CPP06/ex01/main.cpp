
#include <iostream>
#include "Bureaucrat.hpp"

int main(int argc, char ** argv)
{
	if (argc == 1) std::cerr << "please we need an argument" << std::endl;
	if (argc > 2) std::cerr << "please we need only one argument" << std::endl;
	if (argc != 2) return 1;

	
}
