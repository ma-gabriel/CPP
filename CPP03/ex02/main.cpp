#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap Peter("The pacifist");
    FragTrap Steve("The violent");
    FragTrap Jack("The kind");
    
    Jack.highFivesGuys();
    for (int i = 0; i<11; i++){
        Steve.attack("Peter");
        Peter.takeDamage(20);
        Peter.beRepaired(10);
    }
}