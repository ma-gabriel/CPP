#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog"){
    _brain = new Brain();
    //std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog &ref): Animal(ref){
    _type = ref._type;
    _brain = new Brain(*ref._brain);
    //std::cout << "Copy constructor called Dog" << std::endl;
}

Dog::~Dog(){
    delete _brain;
    //std::cout << "Destructor called for Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &ref){
    //std::cout << "Copy assignement operator called for Dog" << std::endl;
    _type = ref._type;
	*_brain = *ref._brain;
    return *this;
}

void Dog::makeSound(void) const{
    std::cout << "Barks intensivly" << std::endl;
}

std::string &Dog::getIdeaAt(unsigned int index){
	return _brain->getIdeaAt(index);
}

void Dog::setIdeaAt(unsigned int index, const std::string &idea){
	_brain->setIdeaAt(index, idea);
}
