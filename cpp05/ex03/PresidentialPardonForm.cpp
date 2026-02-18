#include "PresidentialPardonForm.hpp"

#include <exception>
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("unnamed Presi", 25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presi ", 25, 5), _target(target) {};

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
    : AForm(obj), _target(obj.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj);
    }
    return *this;
}

std::string PresidentialPardonForm::getTarget(void) const
{
  return this->_target;
}

void  PresidentialPardonForm::executeAction(std::string bureucratName) const
{
    (void) bureucratName;
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


std::ostream& operator<<(std::ostream &os, const PresidentialPardonForm &obj)
{
    os << obj.getName() << ", signed: " << obj.isSigned();
    os << " ,required sign grade: " << obj.getRequiredSignGrade();
    os << " ,required exec grade: " << obj.getRequiredExecGrade();
    return (os);
}
