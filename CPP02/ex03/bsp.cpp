
#include "Point.hpp"
#include <iostream>

static Fixed find_area_triangle(Point const &a, Point const &b, Point const &c);

bool bsp( Point const a, Point const b, Point const c, Point const point){
    return 
    find_area_triangle(a, b, c) == 
    find_area_triangle(a, b, point) +
    find_area_triangle(b, c, point) +
    find_area_triangle(c, a, point);
}

static Fixed find_area_triangle(Point const &a, Point const &b, Point const &c)
{
    return Fixed(0.5) * Fixed(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())).abs();
}