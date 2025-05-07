#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <list>


template <typename T>
void display(T &container)
{
    typename T::iterator it = container.begin();
    typename T::iterator end = container.end();

    while (it != end)
		std::cout << *(it++) << " ";
	std::cout << std::endl;
}


int main()
{
	std::list<int> container;
	//std::vector<int> container;
	//std::deque<int> container;
	int nm[] = {1, 2, 3, 4, 5, 6, 7};
	for (size_t i = 0; i < sizeof(nm) / sizeof(int); i++)
		container.push_back(nm[i]);
	display(container);

    try
	{
        int& res = easyfind(container, 19);
        std::cout << res << std::endl;
        res = -1;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
	}

	display(container);

    return 0;
}
