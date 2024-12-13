#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	protected:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_damages;
	
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &ref);
		~ClapTrap(void);
		ClapTrap &operator=(const ClapTrap &ref);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
