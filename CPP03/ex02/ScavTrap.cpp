
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Default constructor (ScavTrap) called for " << name << std::endl;
	_hp = 100;
	_ep = 50;
	_damages = 20;
}

ScavTrap::ScavTrap(ScavTrap &ref) : ClapTrap(ref)
{
	std::cout << "Copy constructor (ScavTrap) called for " << ref._name << std::endl;
	_name = ref._name;
	_hp = ref._hp;
	_ep = ref._ep;
	_damages = ref._damages;
}

ScavTrap::~ScavTrap(){
	std::cout << "Destructor (ScavTrap) called for " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ref){
	_name = ref._name;
	_hp = ref._hp;
	_ep = ref._ep;
	_damages = ref._damages;
	return *this;
}

void ScavTrap::guardGate(){
	std::cout << _name << " is now in gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!_hp){
		std::cout << "ScavTrap " << _name << " couldn't attack because no hit points left" << std::endl;
		return ;
	}
	if (!_ep){
		std::cout << "ScavTrap " << _name << " couldn't attack because no energy points left" << std::endl;
		return ;
	}
	_ep--;
	std::cout << "ScavTrap " << _name << " wants to attack " << target << " for " << _damages << std::endl;
}