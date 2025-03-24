
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
class Bureaucrat;

class Form {
	private:
		const std::string _name;
		const short _signGrade;
		const short _execGrade;
        bool _isSigned;
		Form &operator=(const Form &ref);

	public:
		Form(void);
		Form(const std::string &name);
		Form(const std::string &name, const short &signGrade, const short &execGrade);
		Form(const Form &ref);
		~Form(void);
		const std::string &getName(void) const;
		const short &getSignGrade(void) const;
		const short &getExecGrade(void) const;
		const bool &getIsSigned(void) const;
        void beSigned(const Bureaucrat &signer);
		class GradeTooHighException: public std::exception {
			public:
  				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
  				const char* what() const throw();
		};
		class IsAlreadySigned: public std::exception {
			public:
  				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream & os, const Form &t);

#endif