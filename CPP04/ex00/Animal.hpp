#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
	protected:
		std::string _type;

    public:
		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &ref);
		Animal &operator=(const Animal &ref);
		virtual ~Animal(void);
		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif