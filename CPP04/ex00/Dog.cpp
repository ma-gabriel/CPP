#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog"){
    std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog &ref): Animal(ref){
    _type = ref._type;
    std::cout << "Copy constructor called Dog" << std::endl;
}

Dog::~Dog(){
    std::cout << "Destructor called for Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &ref){
    std::cout << "Copy assignement operator called for Dog" << std::endl;
    _type = ref._type;
    return *this;
}

void Dog::makeSound(void) const{
    std::cout << "Barks intensivly" << std::endl;
}
