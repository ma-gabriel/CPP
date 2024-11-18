#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(){
    this->value = 0;
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int ref){
    this->value = ref << this->bits;
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const double ref){
    this->value = (int) (ref * (1 << this->bits));
    //std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref){
    this->value = ref.value;
    //std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(){
    //std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &ref){
    //std::cout << "Copy assignement operator called" << std::endl;
    this->value = ref.value;
    return *this;
}

int Fixed::getRawBits(void) const{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw){
    //std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float Fixed::toFloat( void ) const{
    return (float) this->value / (1 << this->bits);
}

int Fixed::toInt( void ) const{
    return this->value >> this->bits;
}

std::ostream &operator<<(std::ostream & os, const Fixed &t){
    os << (float) t.value / (1 << t.bits);
    return os;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~arithmetic operators~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Fixed Fixed::operator+(const Fixed &term){
    this->value += term.value;
    return *this;
}

Fixed Fixed::operator-(const Fixed &term){
    this->value -= term.value;
    return *this;
}

Fixed Fixed::operator*(const Fixed &term){
    this->value = ((long)this->value * term.value) >> this->bits;
    return *this;
}

Fixed Fixed::operator/(const Fixed &term){
    this->value = ((long) this->value << this->bits) / term.value;
    return *this;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~Logical operators~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool Fixed::operator==(const Fixed &ref){
    return (this->value == ref.value);
}

bool Fixed::operator>(const Fixed &ref){
    return (this->value > ref.value);
}

bool Fixed::operator<(const Fixed &ref){
    return (this->value < ref.value);
}

bool Fixed::operator>=(const Fixed &ref){
    return (this->value >= ref.value);
}

bool Fixed::operator<=(const Fixed &ref){
    return (this->value <= ref.value);
}

bool Fixed::operator!=(const Fixed &ref){
    return (this->value != ref.value);
}

float Fixed::operator++(void){
    this->value++;
    return (float) this->value / (1 << this->bits);
}

float Fixed::operator++(int){
    this->value++;
    return (float) (this->value - 1) / (1 << this->bits);
}

float Fixed::operator--(void){
    this->value--;
    return (float) this->value / (1 << this->bits);
}

float Fixed::operator--(int){
    this->value--;
    return (float) (this->value + 1) / (1 << this->bits);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~other functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Fixed &Fixed::min(Fixed &a, Fixed &b){
    return (a.value < b.value) ? a:b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
    return (a.value < b.value) ? a:b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
    return (a.value > b.value) ? a:b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
    return (a.value > b.value) ? a:b;
}

Fixed &Fixed::abs(void){
    if (this->value < 0)
        this->value *= -1;
    return *this;
}


