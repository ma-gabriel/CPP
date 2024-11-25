#ifndef CAT_HPP
# define CAT_HPP

# include <ostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	protected:
		std::string type;
		Brain *brain;
    
    public:
		Cat(void);
		Cat(const Cat &ref);
		Cat &operator=(const Cat &ref);
		~Cat(void);
		void makeSound(void) const;
};

#endif