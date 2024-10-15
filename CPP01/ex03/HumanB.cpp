#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon weapon)
{
    this->name = name;
    this->weaponPTR = &weapon;
}

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weaponPTR = NULL;
}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weaponPTR = &weapon;
}

void HumanB::attack()
{
    if (weaponPTR)
        std::cout << this->name << " attacks with their " << (*(this->weaponPTR)).getType() << "\n";
    else
        std::cout << this->name << " attacks with their bare fists\n";
}

