#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
		FragTrap(std::string name);
		FragTrap(FragTrap &ref);
        FragTrap &operator=(const FragTrap &ref);
		~FragTrap(void);
        void highFivesGuys(void);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif