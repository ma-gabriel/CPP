#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
    : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
    : _value(ref._value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &ref){
	std::cout << "Copy assignment operator called" << std::endl;
    _value = ref._value;
    return *this;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}