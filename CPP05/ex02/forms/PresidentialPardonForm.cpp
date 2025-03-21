
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), _target("")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
    : AForm("PresidentialPardonForm", 145, 137), _target(ref._target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const AForm &ref)
{
    (void) ref;
    //does basically nothing, thus private
    return *this;
}

void PresidentialPardonForm::concreteExcecute(void) const
{
    std::cout << _target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}