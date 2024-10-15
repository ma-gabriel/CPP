#include "Zombie.hpp"

Zombie::~Zombie(void)
{
    std::cout << this->name << " is no more, again\n";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}