
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Constructor called for " << this->name << std::endl;
    this->name = name;
    this->damages = 0;
    this->ep = 10;
    this->hp = 10;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor called for " << this->name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << this->name << " wants to attack " << target << " for " << this->damages << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > this->hp) this->hp = 0;
    else this->hp -= amount;
    std::cout << "ClapTrap " << this->name << " got damaged for " \
        << amount << " hp and has " << this->hp << " left\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!hp){
        std::cout << "ClapTrap " << this->name << " couldn't repair itself because no hit points left" << std::endl;
        return ;
    }
    if (!ep){
        std::cout << "ClapTrap " << this->name << " couldn't repair itself because no energy points left" << std::endl;
        return ;
    }
    ep--;
    this->hp += amount;
    std::cout << "ClapTrap " << this->name << " repaired itself for " << amount << " hp" << std::endl;
}