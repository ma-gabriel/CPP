#include "Weapon.hpp"

Weapon::Weapon(std::string const type)
{
	_type = type;
}

Weapon::Weapon()
{
	_type = "";
}

Weapon::~Weapon(void){}

void Weapon::setType(std::string const type){
    _type = type;
}

const std::string &Weapon::getType()
{
    return _type;
}