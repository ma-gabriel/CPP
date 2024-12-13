
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Default constructor (FragTrap) called for " << name << std::endl;
	_hp = 100;
	_ep = 100;
	_damages = 30;
}

FragTrap::FragTrap(FragTrap &ref) : ClapTrap(ref)
{
	std::cout << "Copy constructor (FragTrap) called for " << ref._name << std::endl;
	_name = ref._name;
	_hp = ref._hp;
	_ep = ref._ep;
	_damages = ref._damages;
}

FragTrap::~FragTrap(){
	std::cout << "Destructor (FragTrap) called for " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ref){
	_name = ref._name;
	_hp = ref._hp;
	_ep = ref._ep;
	_damages = ref._damages;
	return *this;
}

void FragTrap::highFivesGuys(void){
	std::cout << _name << " wants to high five you"<< std::endl;
}