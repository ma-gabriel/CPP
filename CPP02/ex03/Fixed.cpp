#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
    : _value(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
    : _value(ref._value) {
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const double ref)
    : _value((int) (ref * (1 << _bits))) {
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int ref)
    : _value(ref << _bits) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::~Fixed(){
    // std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &ref){
    //std::cout << "Copy assignement operator called" << std::endl;
    _value = ref._value;
    return *this;
}

int Fixed::getRawBits(void) const{
    //std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw){
    //std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

float Fixed::toFloat( void ) const{
    return (float) _value / (1 << _bits);
}

int Fixed::toInt( void ) const{
    return _value >> _bits;
}

std::ostream &operator<<(std::ostream & os, const Fixed &t){
    os << t.toFloat();
    return os;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~arithmetic operators~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Fixed Fixed::operator+(const Fixed &term){
    _value += term._value;
    return *this;
}

Fixed Fixed::operator-(const Fixed &term){
    _value -= term._value;
    return *this;
}

Fixed Fixed::operator*(const Fixed &term){
    _value = ((long)_value * term._value) >> _bits;
    return *this;
}

Fixed Fixed::operator/(const Fixed &term){
    _value = ((long) _value << _bits) / term._value;
    return *this;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~Logical operators~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool Fixed::operator==(const Fixed &ref){
    return (_value == ref._value);
}

bool Fixed::operator>(const Fixed &ref){
    return (_value > ref._value);
}

bool Fixed::operator<(const Fixed &ref){
    return (_value < ref._value);
}

bool Fixed::operator>=(const Fixed &ref){
    return (_value >= ref._value);
}

bool Fixed::operator<=(const Fixed &ref){
    return (_value <= ref._value);
}

bool Fixed::operator!=(const Fixed &ref){
    return (_value != ref._value);
}

float Fixed::operator++(void){
    _value++;
    return (float) _value / (1 << _bits);
}

float Fixed::operator++(int){
    _value++;
    return (float) (_value - 1) / (1 << _bits);
}

float Fixed::operator--(void){
    _value--;
    return (float) _value / (1 << _bits);
}

float Fixed::operator--(int){
    _value--;
    return (float) (_value + 1) / (1 << _bits);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~other functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Fixed &Fixed::min(Fixed &a, Fixed &b){
    return (a._value < b._value) ? a:b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
    return (a._value < b._value) ? a:b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
    return (a._value > b._value) ? a:b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
    return (a._value > b._value) ? a:b;
}

Fixed &Fixed::abs(void){
    if (_value < 0)
        _value *= -1;
    return *this;
}


