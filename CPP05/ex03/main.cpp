
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat President("Eliot", 1);
		Intern Philip;
		AForm *form = Philip.makeForm("robotomy request", "Dora The explorer");
		President.signForm(*form);
		President.execForm(*form);
		delete form;
		form = Philip.makeForm("freeze request", "Dora The explorer");
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
