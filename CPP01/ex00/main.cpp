#include "Zombie.hpp"
#include <iostream>

int main()
{
    Zombie jeanne = Zombie("Jeanne");
    jeanne.announce();

    Zombie *titouan = newZombie("titouan");
	titouan->announce();
    
    randomChump("George");

    delete titouan;
    return (0);
}