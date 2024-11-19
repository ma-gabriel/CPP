#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap Peter("The pacifist");
    ScavTrap Steve("The violent");
    ScavTrap Jack("The guard");
    
    Jack.guardGate();
    for (int i = 0; i<11; i++){
        Steve.attack("Peter");
        Peter.takeDamage(20);
        Peter.beRepaired(10);
    }
}