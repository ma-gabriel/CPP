#include "Point.hpp"
#include <iostream>

Point::Point(){
    this->x = 0;
    this->y = 0;
}

Point::Point(const float x, const float y){
    this->x = x;
    this->y = y;
}

Point::Point(const Point &ref){
    this->x = ref.x;
    this->y = ref.y;
}

Point::~Point(){}

Point &Point::operator=(const Point &ref){
    this->x = ref.x;
    this->y = ref.y;
    return *this;
}

Fixed Point::getX(void) const{
    return this->x;
}

Fixed Point::getY(void) const{
    return this->y;
}