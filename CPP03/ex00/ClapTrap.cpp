
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	:_name(name), _hp(10), _ep(10), _damages(0)
{
	std::cout << "Default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &ref)
	:_name(ref._name), _hp(ref._hp), _ep(ref._ep), _damages(ref._damages)
{
	std::cout << "Copy constructor called for " << _name << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!_hp){
		std::cout << "ClapTrap " << _name << " couldn't attack because no hit points left" << std::endl;
		return ;
	}
	if (!_ep){
		std::cout << "ClapTrap " << _name << " couldn't attack because no energy points left" << std::endl;
		return ;
	}
	_ep--;
	std::cout << "ClapTrap" << _name << " wants to attack " << target << " for " << _damages << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ref){
	_name = ref._name;
	_hp = ref._hp;
	_ep = ref._ep;
	_damages = ref._damages;
	return *this;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hp) _hp = 0;
	else _hp -= amount;
	std::cout << "ClapTrap " << _name << " got damaged for " \
		<< amount << " hp and has " << _hp << " left\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hp){
		std::cout << "ClapTrap " << _name << " couldn't repair itself because no hit points left" << std::endl;
		return ;
	}
	if (!_ep){
		std::cout << "ClapTrap " << _name << " couldn't repair itself because no energy points left" << std::endl;
		return ;
	}
	_ep--;
	_hp += amount;
	if (_hp < amount)
		_hp = -1;
	std::cout << "ClapTrap " << _name << " repaired itself and has now " << _hp << " hp" << std::endl;
}