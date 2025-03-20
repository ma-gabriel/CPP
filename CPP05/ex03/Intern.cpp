#include "Intern.hpp"
#include <iostream>


Intern::Intern()
{
    std::cout << "Default constructor called for Intern" << std::endl;
}

Intern::Intern(const Intern &ref)
{
    (void) ref;
    std::cout << "Copy constructor called Intern" << std::endl;
}

Intern::~Intern(){
    std::cout << "Destructor called for Intern" << std::endl;
}

Intern &Intern::operator=(const Intern &ref){
    (void) ref;
    std::cout << "Copy assignement operator called for Intern (no use)" << std::endl;
    return *this;
}


static AForm* createRRF(std::string target) {
    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
    return new RobotomyRequestForm(target);
}

static AForm* createPPF(std::string target) {
    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
    return new PresidentialPardonForm(target);
}

static AForm* createSCF(std::string target) {
    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string form, std::string target){
    AForm *(*funcs[3])(std::string) = {createRRF, createPPF, createSCF};
	std::string breakpoints[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for (int i = 0; i < 3; i++)
		if (breakpoints[i] == form)
			return (funcs[i])(target);
    std::cout << "Sorry boss i don't knwo what \"" << form << "\" form is." << std::endl;
    return NULL;
}

