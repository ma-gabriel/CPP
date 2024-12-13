#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point a(1, 1);
    Point b(5, 1);
    Point c(3, 4);

	// on the side of the triangle is false, according to subject
    std::cout << (bsp(a, b, c, Point(3, 1)) ? "true" : "false") << std::endl;

    std::cout << (bsp(a, b, c, Point(2, 2)) ? "true" : "false") << std::endl;

    std::cout << (bsp(a, b, c, Point(4, 2)) ? "true" : "false") << std::endl;

    std::cout << (bsp(a, b, c, Point(3, 3)) ? "true" : "false") << std::endl;

    std::cout << (bsp(a, b, c, Point(6, 5)) ? "true" : "false") << std::endl;

    std::cout << (bsp(a, b, c, Point(2, 3)) ? "true" : "false") << std::endl;

    std::cout << (bsp(a, b, c, Point(1, 2)) ? "true" : "false") << std::endl;

    std::cout << (bsp(a, b, c, Point(-1, 0)) ? "true" : "false") << std::endl;
    
    return 0;
}