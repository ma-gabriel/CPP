#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(){
    this->value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int ref){
    this->value = ref << this->bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const double ref){
    this->value = (int) (ref * (1 << this->bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref){
    this->value = ref.value;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &ref){
    std::cout << "Copy assignement operator called" << std::endl;
    this->value = ref.value;
    return *this;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float Fixed::toFloat( void ) const{
    return (float) this->value / (1 << this->bits);
}

int Fixed::toInt( void ) const{
    return this->value >> this->bits;
}

std::ostream &operator<<(std::ostream & os, const Fixed &t){
    os << t.toFloat();
    return os;
}