#include "Weapon.hpp"

Weapon::Weapon(std::string const type)
{
	this->type = type;
}

Weapon::Weapon()
{
	this->type = "";
}

Weapon::~Weapon(void){}

void Weapon::setType(std::string const type){
    this->type = type;
}

const std::string &Weapon::getType()
{
    return this->type;
}