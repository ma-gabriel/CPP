#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form()
	:_name(""), _signGrade(150), _execGrade(150), _isSigned(false)
{
    std::cout << "Default constructor called for Form" << std::endl;
}

Form::Form(const std::string &name)
	:_name(name), _signGrade(150), _execGrade(150), _isSigned(false)
{
    std::cout << "std::string constructor called for Form (both grade 150)" << std::endl;
}

Form::Form(const std::string &name, const short &signGrade, const short &execGrade)
	:_name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
    if (signGrade > 150 or execGrade > 150) throw GradeTooLowException();
    if (signGrade < 1 or execGrade < 1) throw GradeTooHighException();
    std::cout << "Full constructor called for Form" << std::endl;
}

Form::Form(const Form &ref)
	:_name(ref._name), _signGrade(ref._signGrade), _execGrade(ref._execGrade), _isSigned(false)
{
    std::cout << "Copy constructor called Form" << std::endl;
}

Form::~Form(){
    std::cout << "Destructor called for Form" << std::endl;
}

Form &Form::operator=(const Form &ref){
    (void) ref;
    std::cout << "Copy assignement operator (doesn't do anything) called for Form " << _name << std::endl;
    return *this;
}


const std::string &Form::getName(void) const {
    return _name;
}

const short &Form::getExecGrade(void) const {
    return _execGrade;
}

const short &Form::getSignGrade(void) const {
    return _signGrade;
}

const bool &Form::getIsSigned(void) const {
    return _isSigned;
}

void Form::beSigned(const Bureaucrat &signer)
{
    if (signer.getGrade() > _signGrade) throw GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream & os, const Form &t)
{
    os << t.getName() << ", form exec grade " << t.getExecGrade() << " and sign grade " << t.getSignGrade() << ".";
    return os;
}
