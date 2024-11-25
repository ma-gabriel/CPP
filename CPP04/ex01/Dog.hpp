#ifndef DOG_HPP
# define DOG_HPP

# include <ostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{
	protected:
		std::string type;
		Brain *brain;
    
    public:
		Dog(void);
		Dog(const Dog &ref);
		Dog &operator=(const Dog &ref);
		~Dog(void);
		void makeSound(void) const;
};

#endif