
#include <iostream>
#include "utils.hpp"

int main()
{
	Base *example = generate();

	identify(example);
	identify(*example);
}
