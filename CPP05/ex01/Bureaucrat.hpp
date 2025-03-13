
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include "Form.hpp"

class Bureaucrat {
	private:
		const std::string _name;
		short _grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name);
		Bureaucrat(const std::string &name, const short &grade);
		Bureaucrat(const Bureaucrat &ref);
		Bureaucrat &operator=(const Bureaucrat &ref);
		~Bureaucrat(void);
		const std::string &getName(void) const;
		const short &getGrade(void) const;
		const short &decrementGrade(void);
		const short &incrementGrade(void);
		void signForm(Form &form);
		class GradeTooHighException: public std::exception {
			public:
  				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
  				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream & os, const Bureaucrat &t);

#endif