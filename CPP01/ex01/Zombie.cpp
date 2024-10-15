#include "Zombie.hpp"

Zombie::~Zombie(void)
{
    std::cout << this->name << " is no more, again\n";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie(void)
{
	this->name = "";
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name){
    this->name = name;
}