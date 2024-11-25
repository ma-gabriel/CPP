#include "Brain.hpp"
#include <iostream>

Brain::Brain(){
    std::cout << "Default constructor called for Brain" << std::endl;
    for (size_t i = 0; i < sizeof(ideas) / sizeof(std::string); i++)
        this->ideas[i] = std::string();
}

Brain::Brain(const Brain &ref){
    std::cout << "Copy constructor called Brain" << std::endl;
    for (size_t i = 0; i < sizeof(ideas) / sizeof(std::string); i++)
        this->ideas[i] = ref.ideas[i];
}

Brain::~Brain(){
    std::cout << "Destructor called for Brain" << std::endl;
}

Brain &Brain::operator=(const Brain &ref){
    std::cout << "Copy assignement operator called for Brain" << std::endl;
    for (size_t i = 0; i < sizeof(ideas) / sizeof(std::string); i++)
        this->ideas[i] = ref.ideas[i];
    return *this;
}
