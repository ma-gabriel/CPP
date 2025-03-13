
#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat George("George", 150);
		std::cout << "About to decrement " << George << std::endl;
		George.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
