#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(){
    this->type = "";
    std::cout << "Default constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type){
    this->type = type;
    std::cout << "std::string constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref){
    this->type = ref.type;
    std::cout << "Copy constructor called WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "Destructor called for WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &ref){
    std::cout << "Copy assignement operator called for WrongAnimal" << std::endl;
    this->type = ref.type;
    return *this;
}

std::string WrongAnimal::getType(void) const{
    return this->type;
}

void WrongAnimal::makeSound(void) const{
    std::cout << "*WrongAnimal's sounds*" << std::endl;
}