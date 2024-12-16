#include "Brain.hpp"
#include <iostream>

Brain::Brain(){
    //std::cout << "Default constructor called for Brain" << std::endl;
    for (size_t i = 0; i < sizeof(_ideas) / sizeof(std::string); i++)
        _ideas[i] = std::string();
}

Brain::Brain(const Brain &ref){
    //std::cout << "Copy constructor called Brain" << std::endl;
    for (size_t i = 0; i < sizeof(_ideas) / sizeof(std::string); i++)
        _ideas[i] = ref._ideas[i];
}

Brain::~Brain(){
    //std::cout << "Destructor called for Brain" << std::endl;
}

Brain &Brain::operator=(const Brain &ref){
    //std::cout << "Copy assignement operator called for Brain" << std::endl;
    for (size_t i = 0; i < sizeof(_ideas) / sizeof(std::string); i++)
        _ideas[i] = ref._ideas[i];
    return *this;
}

void Brain::setIdeaAt(unsigned int index, const std::string &idea){
	_ideas[index % (sizeof(_ideas) / sizeof(std::string))] = idea;
}

std::string &Brain::getIdeaAt(unsigned int index){
	return (_ideas[index % (sizeof(_ideas) / sizeof(std::string))]);
}