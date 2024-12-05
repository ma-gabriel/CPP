#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon weapon)
{
    _name = name;
    _weaponPTR = &weapon;
}

HumanB::HumanB(std::string name)
{
    _name = name;
    _weaponPTR = NULL;
}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &weapon)
{
    _weaponPTR = &weapon;
}

void HumanB::attack()
{
    if (_weaponPTR)
        std::cout << _name << " attacks with their " << (*(_weaponPTR)).getType() << "\n";
    else
        std::cout << _name << " attacks with their bare fists\n";
}

