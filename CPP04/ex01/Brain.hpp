#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include "Animal.hpp"

class Brain{
	private:
		std::string _ideas[100];
    
    public:
		Brain(void);
		Brain(const Brain &ref);
		Brain &operator=(const Brain &ref);
		~Brain(void);

		void setIdeaAt(unsigned int index, const std::string &idea);
		std::string &getIdeaAt(unsigned int index);
};

#endif