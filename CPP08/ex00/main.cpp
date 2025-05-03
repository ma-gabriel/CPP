

#include "easyfind.hpp"

#include<iostream>
#include<array>

using namespace std;

int main()
{
	array<int,6> ar = {1, 2, 3, 4, 5, 6};
    for ( int i=0; i<6; i++)
    std::cout << ar[i] << " ";
    std::cout << std::endl;



	int &res = easyfind(ar, 10);
	std::cout << res << std::endl;
	res = -1;
	

    for ( int i=0; i < 6; i++)
    std::cout << ar[i] << " ";
    std::cout << std::endl;


	return 0;
}