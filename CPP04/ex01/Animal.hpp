#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <ostream>

class Animal {
	protected:
		std::string type;

    public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &ref);
		Animal &operator=(const Animal &ref);
		virtual ~Animal(void);
		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif