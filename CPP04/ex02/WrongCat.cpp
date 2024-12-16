#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "Default constructor called for WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref): WrongAnimal(ref){
    _type = ref._type;
    std::cout << "Copy constructor called WrongCat" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "Destructor called for WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &ref){
    std::cout << "Copy assignement operator called for WrongCat" << std::endl;
    _type = ref._type;
    return *this;
}


void WrongCat::makeSound(void) const{
    std::cout << "MIAOW MIAOW" << std::endl;
}