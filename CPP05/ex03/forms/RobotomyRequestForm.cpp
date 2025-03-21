
#include "RobotomyRequestForm.hpp"
#include <cstdlib> 
#include <ctime>

__attribute__((constructor))
static void randomizeRobotomyRequest() {
    std::srand(std::time((long *) 0));
}

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target("")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
    : AForm("RobotomyRequestForm", 145, 137), _target(ref._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const AForm &ref)
{
    (void) ref;
    //does basically nothing, thus private
    return *this;
}
void RobotomyRequestForm::concreteExcecute(void) const
{
    std::cout << "*drilling noises*\n";
    if (std::rand() & 1)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << "The robotomy failed" << std::endl;
}