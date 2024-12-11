#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a(1234.4321f);
    Fixed const b( 10 );
    Fixed c = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "a != b is " << (a != b) << std::endl;
    std::cout << "a != c is " << (a != c) << std::endl;
    std::cout << "a >= b is " << (a >= b) << std::endl;
    std::cout << "a <= b is " << (a <= b) << std::endl;
    std::cout << "a > b is " << (a > b) << std::endl;
    std::cout << "a < b is " << (a < b) << std::endl;
    std::cout << "a == b is " << (a == b) << std::endl;
    std::cout << "a == c is " << (a == c) << std::endl;
    std::cout << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "c raw bits is " << c.getRawBits() << std::endl;
    std::cout << "c++ is " << c++ << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "c raw bits is " << c.getRawBits() << std::endl;
    std::cout << "a == c is " << (a == c) << std::endl;
    std::cout << "++c is " << ++c << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "c raw bits is " << c.getRawBits() << std::endl;
    std::cout << std::endl;
    std::cout << "min between 10.5 and 42 is " <<  Fixed::min(10.5, 42) << std::endl; 
    std::cout << "max between 10.5 and 42 is " <<  Fixed::max(10.5, 42) << std::endl;
    std::cout << std::endl;
    std::cout << "10.5 + 42 = " << Fixed(10.5) + Fixed(42) << std::endl; 
    std::cout << "10.5 - 42 = " << Fixed(10.5) - Fixed(42) << std::endl;
    std::cout << "10.5 * 42 = " << Fixed(10.5) * Fixed(42) << std::endl; 
    std::cout << "10.5 / 42 = " << Fixed(10.5) / Fixed(42) << std::endl;
    return 0;
}