
#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"


int main()
{
	Data original(0);


	Data copy = 16;
	std::cout << (original == copy ? "true" : "false") << std::endl;

	copy = *(Serializer::deserialize(Serializer::serialize(&original)));
	std::cout << (original == copy ? "true" : "false") << std::endl;

}
