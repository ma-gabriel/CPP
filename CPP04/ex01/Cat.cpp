#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat"){
    this->brain = new Brain();
    std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat &ref): Animal(ref){
    this->type = ref.type;
    this->brain = new Brain(*ref.brain);
    std::cout << "Copy constructor called Cat" << std::endl;
}

Cat::~Cat(){
    delete this->brain;
    std::cout << "Destructor called for Cat" << std::endl;
}

Cat &Cat::operator=(const Cat &ref){
    std::cout << "Copy assignement operator called for Cat" << std::endl;
    this->type = ref.type;
    return *this;
}


void Cat::makeSound(void) const{
    std::cout << "Barks intensivly" << std::endl;
}