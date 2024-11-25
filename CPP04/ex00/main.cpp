
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* garfield = new Cat();
        const Animal* odie = new Dog();
        std::cout << garfield->getType() << " " << std::endl;
        std::cout << odie->getType() << " " << std::endl;
        garfield->makeSound(); //will output the cat sound!
        odie->makeSound();
        meta->makeSound();
        delete garfield;
        delete odie;
        delete meta;
    }
    std::cout << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* garfield = new WrongCat();
        std::cout << garfield->getType() << " " << std::endl;
        garfield->makeSound(); //will output the cat sound!
        meta->makeSound();
        delete garfield;
        delete meta;
    }
    return 0;
}