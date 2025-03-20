
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat George("George", 140);
		ShrubberyCreationForm test("TAAAARGET");

		George.signForm(test);
		George.execForm(test);
		for (int i = 0; i < 10; i++) George.incrementGrade();
		std::cout << "I am just better" << std::endl;
		George.execForm(test);

		Bureaucrat President("Céline", 1);
		RobotomyRequestForm robot("The stuff to robotomize");
		President.signForm(robot);
		for (int i = 0; i < 10; i++)
			robot.execute(President);
		
		PresidentialPardonForm pardon("The guy who stuck a cylinder inside a cylinder");
		President.signForm(pardon);
		President.execForm(pardon);
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
