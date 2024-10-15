#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string name)
{
    Zombie temp = Zombie(name);
    temp.announce();
}