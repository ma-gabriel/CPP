
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>
#define NB 100

int main()
{
    Animal *array[NB];
    for (int i = 0; i < NB; i++) {
        if (i % 2)
            array[i] = new Cat();
        else
            array[i] = new Dog();
    }

	std::cout << std::endl;

	int nb = 1;
    std::cout << array[nb]->getType() << " at index " << nb << " says ";
    array[nb]->makeSound();

	dynamic_cast<Cat *> (array[nb])->setIdeaAt(0, "We should cure cancer");
	std::cout << "cat at index " << nb << " says : " << dynamic_cast<Cat *> (array[nb])->getIdeaAt(0) << std::endl;
	Cat george = *dynamic_cast<Cat *> (array[nb]);

	dynamic_cast<Cat *> (array[nb])->setIdeaAt(0, "i forgot");
	std::cout << "cat at index " << nb << " forgot his brillant indea" << std::endl;
	std::cout << "geoge says : " << george.getIdeaAt(0) << std::endl;
	std::cout << "Yay, deep Copy"<< std::endl;
	std::cout << std::endl;

    for (int i = 0; i < NB; i++)
        delete array[i];
    return 0;
}
#undef NB