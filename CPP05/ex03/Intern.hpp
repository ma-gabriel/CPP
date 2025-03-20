
#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern &ref);
		Intern &operator=(const Intern &ref);
		~Intern(void);
		AForm *makeForm(std::string form, std::string target);
};

std::ostream &operator<<(std::ostream & os, const Intern &t);

#endif