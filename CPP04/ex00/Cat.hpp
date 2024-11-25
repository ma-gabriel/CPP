#ifndef CAT_HPP
# define CAT_HPP

# include <ostream>
# include "Animal.hpp"

class Cat : public Animal {
	protected:
		std::string type;
    
    public:
		Cat(void);
		Cat(const Cat &ref);
		Cat &operator=(const Cat &ref);
		~Cat(void);
		void makeSound(void) const;
};

#endif