
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>
#define NB 50
int main()
{
    Cat *array = new Cat[NB];
    Dog *other_array = new Dog[NB];
    // Animal tmp1 = Animal("capybara");
    // Animal tmp2 = Animal();
    // Animal tmp3;

    delete[] array;
    delete[] other_array;
    return 0;
}
#undef NB