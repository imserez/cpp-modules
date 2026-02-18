#include "RobotomyRequestForm.hpp"

#include <exception>
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("unnamed Robotomy", 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy ", 72, 45), _target(target) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
    : AForm(obj), _target(obj.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    if (this != &obj)
    {
        _signed = obj.isSigned();
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget(void) const
{
  return this->_target;
}

void  RobotomyRequestForm::executeAction(std::string bureucratName) const
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
        throw RobotomyRequestForm::RobotizationFailedException();
}


std::ostream& operator<<(std::ostream &os, const RobotomyRequestForm &obj)
{
    os << obj.getName() << ", signed: " << obj.isSigned();
    os << " ,required sign grade: " << obj.getRequiredSignGrade();
    os << " ,required exec grade: " << obj.getRequiredExecGrade();
    return (os);
}
