
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		void concreteExcecute(void) const;
		RobotomyRequestForm &operator=(const AForm &original);
		RobotomyRequestForm(const RobotomyRequestForm &original);

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm();
};

#endif