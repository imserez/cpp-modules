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
        _signed = obj.isSigned();
    }
    return *this;
}

std::string PresidentialPardonForm::getTarget(void) const
{
  return this->_target;
}

void  PresidentialPardonForm::executeAction(std::string bureucratName) const
{
    int random;

    random = rand() % 2;
    if (random == 1)
    {
        std::cout << "rRr RrR uUu .... ººº...ºº---ºº. " << this->getTarget();
        std::cout << " has been robotomized successfully!" << std::endl;
        std::cout << bureucratName << " executed " << this->getName() << std::endl;
    }
    else
        throw PresidentialPardonForm::RobotizationFailedException();
}


std::ostream& operator<<(std::ostream &os, const PresidentialPardonForm &obj)
{
    os << obj.getName() << ", signed: " << obj.isSigned();
    os << " ,required sign grade: " << obj.getRequiredSignGrade();
    os << " ,required exec grade: " << obj.getRequiredExecGrade();
    return (os);
}
