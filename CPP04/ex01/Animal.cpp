#include "Animal.hpp"
#include <iostream>

Animal::Animal()
	:_type("")
{
    //std::cout << "Default constructor called for Animal" << std::endl;
}

Animal::Animal(const std::string &type)
	:_type(type)
{
    //std::cout << "std::string constructor called for Animal" << std::endl;
}

Animal::Animal(const Animal &ref)
	:_type(ref._type)
{
    //std::cout << "Copy constructor called Animal" << std::endl;
}

Animal::~Animal(){
    //std::cout << "Destructor called for Animal" << std::endl;
}

Animal &Animal::operator=(const Animal &ref){
    //std::cout << "Copy assignement operator called for Animal" << std::endl;
    _type = ref._type;
    return *this;
}

std::string Animal::getType(void) const{
    return _type;
}

void Animal::makeSound(void) const{
    std::cout << "*Animal's sounds*" << std::endl;
}