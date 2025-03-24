
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

AForm::AForm()
	:_name(""), _signGrade(150), _execGrade(150), _isSigned(false)
{
    std::cout << "Default constructor called for AForm" << std::endl;
}

AForm &AForm::operator=(const AForm &ref){
    (void) ref;
    std::cout << "Copy assignement operator (doesn't do anything) called for Form " << _name << std::endl;
    return *this;
}

AForm::AForm(const std::string &name, const short &signGrade, const short &execGrade)
	:_name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
    if (signGrade > 150 or execGrade > 150) throw GradeTooLowException();
    if (signGrade < 1 or execGrade < 1) throw GradeTooHighException();
    std::cout << "Full constructor called for Form" << std::endl;
}

AForm::~AForm(){
    std::cout << "Destructor called for AForm" << std::endl;
}

const std::string &AForm::getName(void) const {
    return _name;
}

const short &AForm::getExecGrade(void) const {
    return _execGrade;
}

const short &AForm::getSignGrade(void) const {
    return _signGrade;
}

const bool &AForm::getIsSigned(void) const {
    return _isSigned;
}

void AForm::beSigned(const Bureaucrat &signer)
{
    if (signer.getGrade() > _signGrade) throw GradeTooLowException();
    if (_isSigned == true) throw IsAlreadySigned();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (getIsSigned() == false) throw IsNotSignedException();
    if (executor.getGrade() > getExecGrade()) throw GradeTooLowException();
    
    concreteExcecute();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::IsNotSignedException::what() const throw()
{
    return "Form is not signed";
}

const char *AForm::IsAlreadySigned::what() const throw()
{
    return "Form was already signed";
}

std::ostream &operator<<(std::ostream & os, const AForm &t)
{
    os << t.getName() << ", AForm exec grade " << t.getExecGrade() << " and sign grade " << t.getSignGrade() << ".";
    return os;
}
