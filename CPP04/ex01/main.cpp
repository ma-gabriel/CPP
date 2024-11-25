
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>
#define NB 50
int main()
{
    Animal *array = new Animal[NB];
    for (int i = 0; i < NB; i++)
    {
        if (i % 2) array[i] = Cat();
        else array[i] = Dog();
    }
    delete[] array;
    return 0;
}
#undef NB