#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *_brain;
    
    public:
		Cat(void);
		Cat(const Cat &ref);
		Cat &operator=(const Cat &ref);
		virtual ~Cat(void);
		virtual void makeSound(void) const;

		void setIdeaAt(unsigned int index, const std::string &idea);
		std::string &getIdeaAt(unsigned int index);
};

#endif