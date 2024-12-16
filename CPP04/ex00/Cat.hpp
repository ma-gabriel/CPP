#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		Cat(const Cat &ref);
		Cat &operator=(const Cat &ref);
		virtual ~Cat(void);
		virtual void makeSound(void) const;
};

#endif