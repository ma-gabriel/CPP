
#include <iostream>
#include "whatever.hpp"

// class test
// {
// 	public:
// 	int _val;
// 	int _key;

// 	test(){};
// 	test(int val, int key):_val(val), _key(key){};
// 	test(const test &ref):_val(ref._val), _key(ref._key){};
// 	~test(){};
// 	test &operator=(const test& ref) {_val = ref._val;_key = ref._key;return *this;}
// 	bool operator>(const test& ref) const{return (this->_val > ref._val ? true : false);}
// 	bool operator<(const test& ref) const{return (this->_val < ref._val ? true : false);}

// };

// int main()
// {
// 	test a(17, 0);
// 	test b(15, 1);

// 	std::cout << "min : " << min(a._val, b._val) << std::endl;
// 	std::cout << "min (key) : "<< (min(a, b)._key) << std::endl;
// 	std::cout << "max : "<< max(a._val, b._val) << std::endl;
// 	std::cout << "max (key) : "<< (max(a, b)._key) << std::endl;

// 	std::cout << "a is " << a._key << " and b is " << b._key << std::endl;
// 	swap(a, b);
// 	std::cout << "a is " << a._key << " and b is " << b._key << std::endl;
// 	return 0;
// }

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
	}