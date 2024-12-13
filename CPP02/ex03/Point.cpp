#include "Point.hpp"
#include <iostream>

Point::Point()
	:_x(0), _y(0) {}

Point::Point(const Fixed x, const Fixed y)
	:_x(x), _y(y) {}

Point::Point(const float x, const float y)
	:_x(x), _y(y) {}

Point::Point(const Point &ref)
	:_x(ref._x), _y(ref._y) {}

Point::~Point(){}

Point &Point::operator=(const Point &ref)
{
	(void) ref;
    return *this;
}

Fixed Point::getX(void) const{
    return _x;
}

Fixed Point::getY(void) const{
    return _y;
}