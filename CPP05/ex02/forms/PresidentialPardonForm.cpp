
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), _target("")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::concreteExcecute(void)
{
    std::cout << _target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}