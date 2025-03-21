
#ifndef PRESIDENTIALPARDON_FORM
# define PRESIDENTIALPARDON_FORM

# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
		void concreteExcecute(void) const;
		PresidentialPardonForm &operator=(const AForm &original);
		PresidentialPardonForm(const PresidentialPardonForm &original);

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();
};

#endif