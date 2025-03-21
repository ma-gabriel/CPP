
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
		void concreteExcecute(void) const;
		ShrubberyCreationForm &operator=(const AForm &ref);
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();
};

#endif