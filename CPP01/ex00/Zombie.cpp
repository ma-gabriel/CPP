#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    std::cout << name << " is among us\n";
	_name = name;
}

Zombie::~Zombie(void)
{
    std::cout << _name << " is no more, again\n";
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}