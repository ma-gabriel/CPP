
#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl karen;
	if (argc > 2)
		for (size_t i = 1; argv[i]; i++)
			karen.complain(argv[i]);
	else {
		karen.complain("DEBUG");
		karen.complain("INFO");
		karen.complain("WARNING");
		karen.complain("ERROR");
	}
}
