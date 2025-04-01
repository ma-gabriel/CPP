
#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> a(10);

	for (size_t i = 0; i < a.size(); i++)
		a[i] = i;
	std::cout << a[7] << std::endl;

	try { a[10] = 4;}
	catch(...) {
		std::cout << "Oh no, an exception\n";
	}
	Array<int>b(1);
	a = b;
	a[0] = 99;

	try { a[1] = 4;}
	catch(...) {
		std::cout << "So it's a smaller size now, only "<< a.size() << " , nice. I hope Valgrind don't notify anything\n";
	}


	return 0;
}

