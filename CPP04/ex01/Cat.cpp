#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat"){
    _brain = new Brain();
    //std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat &ref): Animal(ref)
{
    _type = ref._type;
    _brain = new Brain(*ref._brain);
    //std::cout << "Copy constructor called Cat" << std::endl;
}

Cat::~Cat(){
    delete _brain;
    //std::cout << "Destructor called for Cat" << std::endl;
}

Cat &Cat::operator=(const Cat &ref){
    //std::cout << "Copy assignement operator called for Cat" << std::endl;
    _type = ref._type;
	*_brain = *ref._brain;
    return *this;
}

void Cat::makeSound(void) const{
    std::cout << "MEOW MEOW" << std::endl;
}

std::string &Cat::getIdeaAt(unsigned int index){
	return _brain->getIdeaAt(index);
}

void Cat::setIdeaAt(unsigned int index, const std::string &idea){
	_brain->setIdeaAt(index, idea);
}

