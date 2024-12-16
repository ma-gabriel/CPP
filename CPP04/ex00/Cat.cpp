#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat"){
    std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat &ref): Animal(ref)
{
    _type = ref._type;
    std::cout << "Copy constructor called Cat" << std::endl;
}

Cat::~Cat(){
    std::cout << "Destructor called for Cat" << std::endl;
}

Cat &Cat::operator=(const Cat &ref){
    std::cout << "Copy assignement operator called for Cat" << std::endl;
    _type = ref._type;
    return *this;
}

void Cat::makeSound(void) const{
    std::cout << "MEOW MEOW" << std::endl;
}
