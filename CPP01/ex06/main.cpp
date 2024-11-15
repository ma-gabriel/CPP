
#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl karen;
	if (argc == 1)
		std::cout << "What is Harl saying ?" << std::endl;
	else
		karen.complain(argv[1]);
}
