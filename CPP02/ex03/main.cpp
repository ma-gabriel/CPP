#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point a(0, 0);
    Point b(20, 0);
    Point c(10, 30);
    Point point(10, 15);

    std::cout << (bsp(a, b, c, point) ? "true" : "false") << std::endl;

    point = Point(-1, 0);

    std::cout << (bsp(a, b, c, point) ? "true" : "false") << std::endl;
    
    return 0;
}