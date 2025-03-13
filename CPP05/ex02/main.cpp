
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "forms/ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		ShrubberyCreationForm test;
		test.execute();
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
