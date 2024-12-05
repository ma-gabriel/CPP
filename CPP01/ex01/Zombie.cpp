#include "Zombie.hpp"

Zombie::~Zombie(void)
{
    std::cout << _name << " is no more, again\n";
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::Zombie(void)
{
	_name = "";
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name){
    _name = name;
}