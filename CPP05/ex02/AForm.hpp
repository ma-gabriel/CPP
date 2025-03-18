
#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string _name;
		const short _signGrade;
		const short _execGrade;
        bool _isSigned;
		AForm &operator=(const AForm &ref);
		virtual void concreteExcecute(void) = 0;

	public:
		AForm(void);
		AForm(const AForm &ref);
		AForm(const std::string &name, const short &signGrade, const short &execGrade);
		virtual ~AForm(void);
		const std::string &getName(void) const;
		const short &getSignGrade(void) const;
		const short &getExecGrade(void) const;
		const bool &getIsSigned(void) const;
		void execute(Bureaucrat const & executor);
        virtual void beSigned(const Bureaucrat &signer);
		class GradeTooHighException: public std::exception {
			public:
  				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
  				const char* what() const throw();
		};
		class isNotSignedException: public std::exception {
			public:
  				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream & os, const AForm &t);

#endif