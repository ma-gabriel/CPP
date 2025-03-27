
#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"


int main()
{
	Data original(0);


	Data *copy = Serializer::deserialize(Serializer::serialize(&original));
	std::cout << "there is " << (original == *copy ? "the same" : "a different") << " value" << std::endl;
	std::cout << "there is " << (&original == copy ? "the same" : "a different") << " address" << std::endl;
}
