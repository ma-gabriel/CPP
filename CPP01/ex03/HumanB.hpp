#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB {
	private:
		Weapon *_weaponPTR;
        std::string _name;
    
    public:
		HumanB(std::string name, Weapon type);
		HumanB(std::string name);
		~HumanB(void);
		void setWeapon(Weapon &weapon);
        void attack();
};


#endif