#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name)
{
    Zombie *res = new Zombie(name);
    res->announce();
    return (res);
}