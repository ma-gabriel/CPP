#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
	protected:
		std::string _type;
    
    public:
		WrongAnimal(void);
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &ref);
		WrongAnimal &operator=(const WrongAnimal &ref);
		~WrongAnimal(void);
		std::string getType(void) const;
		void makeSound(void) const;
};

#endif