
#include <iostream>
#include "iter.hpp"

class test
{
	public:
	int _val;
	int _key;

	test(){};
	test(int val, int key):_val(val), _key(key){};
	test(const test &ref):_val(ref._val), _key(ref._key){};
	~test(){};
	test &operator=(const test& ref) {_val = ref._val;_key = ref._key;return *this;}
	bool operator>(const test& ref) const{return (this->_val > ref._val ? true : false);}
	bool operator<(const test& ref) const{return (this->_val < ref._val ? true : false);}
};

void reset(test &t){
	t._val = 0;
}


void add_2(test &t){
	t._val += 2;
}


int main()
{
	test *array = new test[15];

	for (int i = 0; i < 15; i++)
		array[i]._val = i;
	
	for (int i = 0; i < 15; i++)
		std::cout << array[i]._val << " ";
	std::cout << std::endl;

	iter(array, 15, reset);

	for (int i = 0; i < 15; i++)
		std::cout << array[i]._val << " ";
	std::cout << std::endl;
	
	iter(array + 5, 5, add_2);

	for (int i = 0; i < 15; i++)
		std::cout << array[i]._val << " ";
	std::cout << std::endl;

	delete[] array;
}

