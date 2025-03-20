
#ifndef PRESIDENTIALPARDON_FORM
# define PRESIDENTIALPARDON_FORM

# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
		virtual void concreteExcecute(void);

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();
};

#endif