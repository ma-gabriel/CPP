#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <ostream>

class WrongAnimal {
	protected:
		std::string type;
    
    public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &ref);
		WrongAnimal &operator=(const WrongAnimal &ref);
		~WrongAnimal(void);
		std::string getType(void) const;
		void makeSound(void) const;
};

#endif