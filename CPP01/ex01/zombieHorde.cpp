#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *lst = new Zombie[N];

    for (int i = 0; i < N; i++) {
        lst[i].setName(name);
    }

    return (lst);
}