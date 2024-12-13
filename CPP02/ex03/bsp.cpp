
#include "Point.hpp"
#include <iostream>

static inline Fixed cross_product(Point first, Point second, Point aimed);

bool bsp( Point const a, Point const b, Point const c, Point const point){
    Fixed side1 = cross_product(a, b, point);
    Fixed side2 = cross_product(b, c, point);
    Fixed side3 = cross_product(c, a, point);
	return (side1 < 0 && side2 < 0 && side3 < 0) || (side1 > 0 && side2 > 0 && side3 > 0);
}


static inline Fixed cross_product(Point first, Point second, Point aimed)
{
	return (first.getX() - second.getX()) * (first.getY() - aimed.getY())
	 - (first.getY() - second.getY()) * (first.getX() - aimed.getX());
}