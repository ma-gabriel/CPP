#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm()
	:_name(""), _signGrade(150), _execGrade(150), _isSigned(false)
{
    std::cout << "Default constructor called for AForm" << std::endl;
}

AForm::AForm(const std::string &name, const short &signGrade, const short &execGrade)
	:_name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
    if (signGrade > 150 or execGrade > 150) throw GradeTooLowException();
    if (signGrade < 1 or execGrade < 1) throw GradeTooHighException();
    std::cout << "Full constructor called for Form" << std::endl;
}

AForm::AForm(const AForm &ref)
	:_name(ref._name), _signGrade(ref._signGrade), _execGrade(ref._execGrade), _isSigned(false)
{
    std::cout << "Copy constructor called AForm" << std::endl;
}

AForm::~AForm(){
    std::cout << "Destructor called for AForm" << std::endl;
}

AForm &AForm::operator=(const AForm &ref){
    (void) ref;
    std::cout << "Copy assignement operator (doesn't do anything) called for AForm " << _name << std::endl;
    return *this;
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
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream & os, const AForm &t)
{
    os << t.getName() << ", AForm exec grade " << t.getExecGrade() << " and sign grade " << t.getSignGrade() << ".";
    return os;
}
