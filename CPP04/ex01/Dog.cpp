#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog"){
    this->brain = new Brain();
    std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog &ref): Animal(ref){
    this->type = ref.type;
    this->brain = new Brain(*ref.brain);
    std::cout << "Copy constructor called Dog" << std::endl;
}

Dog::~Dog(){
    delete brain;
    std::cout << "Destructor called for Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &ref){
    std::cout << "Copy assignement operator called for Dog" << std::endl;
    this->type = ref.type;
    return *this;
}


void Dog::makeSound(void) const{
    std::cout << "Barks intensivly" << std::endl;
}