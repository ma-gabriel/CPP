#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog &ref);
		Dog &operator=(const Dog &ref);
		~Dog(void);
		void makeSound(void) const;
};

#endif