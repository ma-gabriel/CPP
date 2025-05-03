
#pragma once

#include <iostream>
#include <vector>
#include <exception>

template <typename T>
int &easyfind(T &container, int n)
{
    typename T::iterator it = container.begin();
    typename T::iterator end = container.end();

    while (it != end)
    {
        if (*it == n)
            return *it;
        ++it;
    }

    throw std::runtime_error("Value not found");
}