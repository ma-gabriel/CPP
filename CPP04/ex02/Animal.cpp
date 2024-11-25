#include "Animal.hpp"
#include <iostream>

Animal::Animal(){
    this->type = "";
    std::cout << "Default constructor called for Animal" << std::endl;
}

Animal::Animal(std::string type){
    this->type = type;
    std::cout << "std::string constructor called for Animal" << std::endl;
}

Animal::Animal(const Animal &ref){
    this->type = ref.type;
    std::cout << "Copy constructor called Animal" << std::endl;
}

Animal::~Animal(){
    std::cout << "Destructor called for Animal" << std::endl;
}

Animal &Animal::operator=(const Animal &ref){
    std::cout << "Copy assignement operator called for Animal" << std::endl;
    this->type = ref.type;
    return *this;
}

std::string Animal::getType(void) const{
    return this->type;
}

void Animal::makeSound(void) const{
    std::cout << "*Animal's sounds*" << std::endl;
}