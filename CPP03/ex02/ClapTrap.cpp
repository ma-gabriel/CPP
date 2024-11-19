
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    std::cout << "Default constructor (ClapTrap) called for " << this->name << std::endl;
    this->hp = 10;
    this->ep = 10;
    this->damages = 0;
}

ClapTrap::ClapTrap(ClapTrap &ref)
{
    this->name = ref.name;
    std::cout << "Copy constructor (ClapTrap) called for " << this->name << std::endl;
    this->hp = ref.hp;
    this->ep = ref.ep;
    this->damages = ref.damages;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor (ClapTrap) called for " << this->name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ref){
    this->name = ref.name;
    this->hp = ref.hp;
    this->ep = ref.ep;
    this->damages = ref.damages;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (!this->hp){
        std::cout << "ClapTrap " << this->name << " couldn't attack because no hit points left" << std::endl;
        return ;
    }
    if (!this->ep){
        std::cout << "ClapTrap " << this->name << " couldn't attack because no energy points left" << std::endl;
        return ;
    }
    this->ep--;
    std::cout << "ClapTrap " << this->name << " wants to attack " << target << " for " << this->damages << std::endl;
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
    if (!this->hp){
        std::cout << "ClapTrap " << this->name << " couldn't repair itself because no hit points left" << std::endl;
        return ;
    }
    if (!this->ep){
        std::cout << "ClapTrap " << this->name << " couldn't repair itself because no energy points left" << std::endl;
        return ;
    }
    this->ep--;
    this->hp += amount;
    std::cout << "ClapTrap " << this->name << " repaired itself for " << amount << " hp" << std::endl;
}