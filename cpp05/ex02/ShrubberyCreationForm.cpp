#include "AForm.hpp"

#include <exception>
#include <ostream>

ShrubberyCreationForm::ShrubberyCreationForm() : _name("unnamed ShrubberyCreationForm"), _signed(0), _requiredSignGrade(1), _requiredExecGrade(1) {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 0, 145, 137) 
{
  this->_target = target;
};

ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : _name(obj.getName()),
    _signed(obj.isSigned()),
    _requiredSignGrade(obj.getRequiredSignGrade()),
   _requiredExecGrade(obj.getRequiredExecGrade()),
   _target(obj.getTarget())
{
    checkGrade(obj.getRequiredSignGrade());
    checkGrade(obj.getRequiredExecGrade());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    if (this != &obj)
    {
        _signed = obj.isSigned();
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
  return this->_target;
}

void  ShrubberyCreationForm::execute(Bureaucrat const & executor)
{

}


std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &obj)
{
    os << obj.getName() << ", signed: " << obj.isSigned();
    os << " ,required sign grade: " << obj.getRequiredSignGrade();
    os << " ,required exec grade: " << obj.getRequiredExecGrade();
    return (os);
}
