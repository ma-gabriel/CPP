
#include <iostream>
#include "utils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int main()
{
	Base *example = generate();

	identify(example);
	identify(*example);

	delete example;

	// Base *second = new B();
	// identify(example);
	// identify(*example);

	// delete second;
}
