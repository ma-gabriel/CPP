#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string _type;
    
    public:
		Weapon();
		Weapon(std::string const type);
		~Weapon(void);
        const std::string &getType();
        void setType(std::string const type); 
};

#endif