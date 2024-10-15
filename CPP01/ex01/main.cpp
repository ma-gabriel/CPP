#include "Zombie.hpp"
#include <iostream>

int main()
{
    int     size = 2;
    Zombie  *horde = zombieHorde(size, "Pierre");

    for (int i = 0; i < size; i++){
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}