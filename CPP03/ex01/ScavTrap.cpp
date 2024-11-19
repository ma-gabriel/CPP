
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Default constructor (ScavTrap) called for " << name << std::endl;
    this->hp = 100;
    this->ep = 50;
    this->damages = 20;
}

ScavTrap::ScavTrap(ScavTrap &ref) : ClapTrap(ref)
{
    std::cout << "Copy constructor (ScavTrap) called for " << ref.name << std::endl;
    this->name = ref.name;
    this->hp = ref.hp;
    this->ep = ref.ep;
    this->damages = ref.damages;
}

ScavTrap::~ScavTrap(){
    std::cout << "Destructor (ScavTrap) called for " << this->name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ref){
    this->name = ref.name;
    this->hp = ref.hp;
    this->ep = ref.ep;
    this->damages = ref.damages;
    return *this;
}

void ScavTrap::guardGate(){
    std::cout << this->name << " is now in gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (!this->hp){
        std::cout << "ScavTrap " << this->name << " couldn't attack because no hit points left" << std::endl;
        return ;
    }
    if (!this->ep){
        std::cout << "ScavTrap " << this->name << " couldn't attack because no energy points left" << std::endl;
        return ;
    }
    this->ep--;
    std::cout << "ScavTrap " << this->name << " wants to attack " << target << " for " << this->damages << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (amount > this->hp) this->hp = 0;
    else this->hp -= amount;
    std::cout << "ScavTrap " << this->name << " got damaged for " \
        << amount << " hp and has " << this->hp << " left\n";
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (!this->hp){
        std::cout << "ScavTrap " << this->name << " couldn't repair itself because no hit points left" << std::endl;
        return ;
    }
    if (!this->ep){
        std::cout << "ScavTrap " << this->name << " couldn't repair itself because no energy points left" << std::endl;
        return ;
    }
    this->ep--;
    this->hp += amount;
    std::cout << "ScavTrap " << this->name << " repaired itself for " << amount << " hp" << std::endl;
}