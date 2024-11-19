
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Default constructor (FragTrap) called for " << name << std::endl;
    this->hp = 100;
    this->ep = 100;
    this->damages = 30;
}

FragTrap::FragTrap(FragTrap &ref) : ClapTrap(ref)
{
    std::cout << "Copy constructor (FragTrap) called for " << ref.name << std::endl;
    this->name = ref.name;
    this->hp = ref.hp;
    this->ep = ref.ep;
    this->damages = ref.damages;
}

FragTrap::~FragTrap(){
    std::cout << "Destructor (FragTrap) called for " << this->name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ref){
    this->name = ref.name;
    this->hp = ref.hp;
    this->ep = ref.ep;
    this->damages = ref.damages;
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (!this->hp){
        std::cout << "FragTrap " << this->name << " couldn't attack because no hit points left" << std::endl;
        return ;
    }
    if (!this->ep){
        std::cout << "FragTrap " << this->name << " couldn't attack because no energy points left" << std::endl;
        return ;
    }
    this->ep--;
    std::cout << "FragTrap " << this->name << " wants to attack " << target << " for " << this->damages << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (amount > this->hp) this->hp = 0;
    else this->hp -= amount;
    std::cout << "FragTrap " << this->name << " got damaged for " \
        << amount << " hp and has " << this->hp << " left\n";
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (!this->hp){
        std::cout << "FragTrap " << this->name << " couldn't repair itself because no hit points left" << std::endl;
        return ;
    }
    if (!this->ep){
        std::cout << "FragTrap " << this->name << " couldn't repair itself because no energy points left" << std::endl;
        return ;
    }
    this->ep--;
    this->hp += amount;
    std::cout << "FragTrap " << this->name << " repaired itself for " << amount << " hp" << std::endl;
}

void FragTrap::highFivesGuys(void){
    std::cout << this->name << " wants to high five you"<< std::endl;
}