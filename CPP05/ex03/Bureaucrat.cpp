#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>


Bureaucrat::Bureaucrat()
	:_name(""), _grade(150)
{
    std::cout << "Default constructor called for Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name)
	:_name(name), _grade(150)
{
    std::cout << "std::string constructor called for Bureaucrat (grade 150)" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const short &grade)
	:_name(name), _grade(grade)
{
    if (grade > 150) throw GradeTooLowException();
    if (grade < 1) throw GradeTooHighException();
    std::cout << "Full constructor called for Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)
	:_name(ref._name), _grade(ref._grade)
{
    std::cout << "Copy constructor called Bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Destructor called for Bureaucrat" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref){
    std::cout << "Copy assignement operator called for Bureaucrat " << _name << std::endl;
    _grade = ref._grade;
    return *this;
}


const std::string &Bureaucrat::getName(void) const {
    return _name;
}

const short &Bureaucrat::getGrade(void) const {
    return _grade;
}

const short &Bureaucrat::decrementGrade(void) {
    if (_grade == 150) throw GradeTooLowException();
    return ++_grade;
}
const short &Bureaucrat::incrementGrade(void) {
    if (_grade == 1) throw GradeTooHighException();
    return --_grade;
}

void Bureaucrat::signForm(AForm &form)
{
    if (form.getSignGrade() < _grade){
        std::cout << _name << " couldn’t sign " << form.getName() << " because the form need higher grade" << std::endl;
        return ;
    }
    form.beSigned(*this);
    std::cout <<  _name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::execForm(AForm &form)
{
    if (form.getIsSigned() == false){
        std::cout << _name << " couldn’t execute " << form.getName() << " because the form need to be signed" << std::endl;
        return ;
    }
    if (form.getExecGrade() < _grade){
        std::cout << _name << " couldn’t execute " << form.getName() << " because the form need higher grade" << std::endl;
        return ;
    }
    form.execute(*this);
    std::cout <<  _name << " executed " << form.getName() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream & os, const Bureaucrat &t)
{
    os << t.getName() << ", bureaucrat grade " << t.getGrade() << ".";
    return os;
}

