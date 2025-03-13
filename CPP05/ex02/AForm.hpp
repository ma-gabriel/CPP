
#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		const short _signGrade;
		const short _execGrade;
        bool _isSigned;
		AForm &operator=(const AForm &ref);

	public:
		AForm(void);
		AForm(const AForm &ref);
		AForm(const std::string &name, const short &signGrade, const short &execGrade);
		virtual ~AForm(void);
		const std::string &getName(void) const;
		const short &getSignGrade(void) const;
		const short &getExecGrade(void) const;
		const bool &getIsSigned(void) const;
		virtual void execute(Bureaucrat const & executor) = 0;
        virtual void beSigned(const Bureaucrat &signer);
		class GradeTooHighException: public std::exception {
			public:
  				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
  				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream & os, const AForm &t);

#endif