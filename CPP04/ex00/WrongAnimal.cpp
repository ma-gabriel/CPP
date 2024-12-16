#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(){
    _type = "";
    std::cout << "Default constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type){
    _type = type;
    std::cout << "std::string constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref){
    _type = ref._type;
    std::cout << "Copy constructor called WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "Destructor called for WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &ref){
    std::cout << "Copy assignement operator called for WrongAnimal" << std::endl;
    _type = ref._type;
    return *this;
}

std::string WrongAnimal::getType(void) const{
    return _type;
}

void WrongAnimal::makeSound(void) const{
    std::cout << "*WrongAnimal's sounds*" << std::endl;
}