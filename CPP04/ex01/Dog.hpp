#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *_brain;
    
    public:
		Dog(void);
		Dog(const Dog &ref);
		Dog &operator=(const Dog &ref);
		~Dog(void);
		void makeSound(void) const;

		void setIdeaAt(unsigned int index, const std::string &idea);
		std::string &getIdeaAt(unsigned int index);
};

#endif