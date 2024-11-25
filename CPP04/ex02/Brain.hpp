#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <ostream>
# include "Animal.hpp"

class Brain{
	protected:
		std::string ideas[100];
    
    public:
		Brain(void);
		Brain(const Brain &ref);
		Brain &operator=(const Brain &ref);
		~Brain(void);
};

#endif