#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	private:
		std::string     name;
        unsigned int    hp;
        unsigned int    ep;
        unsigned int    damages;
    
    public:
		ClapTrap(std::string name);
        //ajouter forme canonique
		~ClapTrap(void);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
