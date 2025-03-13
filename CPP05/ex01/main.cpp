
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat George("George", 10);
		std::cout << George << std::endl;
		Form form("Taxing the richs", 1, 1);
		std::cout << form << std::endl;
		George.signForm(form);

		form.beSigned(George);
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
