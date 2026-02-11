#include "AForm.hpp"

#include <exception>
#include <ostream>

class Bureaucrat;

AForm::AForm() : _name("unnamed AForm"), _signed(0), _requiredSignGrade(1), _requiredExecGrade(1) {};

AForm::AForm(std::string name) : _name(name), _signed(0), _requiredSignGrade(1), _requiredExecGrade(1) {};

AForm::AForm(std::string name, int requiredSignGrade, int requiredExecGrade) : _name(name),
    _signed(0),
    _requiredSignGrade(requiredSignGrade),
    _requiredExecGrade(requiredExecGrade)
{
    checkGrade(requiredSignGrade);
    checkGrade(requiredExecGrade);
}

AForm::~AForm() {};

AForm::AForm(const AForm &obj) : _name(obj.getName()),
    _signed(obj.isSigned()),
    _requiredSignGrade(obj.getRequiredSignGrade()),
   _requiredExecGrade(obj.getRequiredExecGrade())
{
    checkGrade(obj.getRequiredSignGrade());
    checkGrade(obj.getRequiredExecGrade());
}

AForm& AForm::operator=(const AForm &obj)
{
    if (this != &obj)
    {
        _signed = obj.isSigned();
    }
    return *this;
}

bool  AForm::isSigned(void) const
{
    return _signed;
}

void  AForm::checkGrade(const int grade)
{
    if (grade < 1)
        throw AForm::GradeTooHighException();
    else if (grade > 150)
        throw AForm::GradeTooLowException();
}

bool AForm::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() > this->_requiredSignGrade)
        throw AForm::GradeTooLowException();
    else
    {
        _signed = true;
        return true;
    }
    return false;
}

std::string AForm::getName(void) const
{
    return this->_name;
}

int   AForm::getRequiredSignGrade(void) const
{
    return _requiredSignGrade;
}
int   AForm::getRequiredExecGrade(void) const
{
    return _requiredExecGrade;
}

void    AForm::execute(Bureaucrat const & executor)
{

}


std::ostream& operator<<(std::ostream &os, const AForm &obj)
{
    os << obj.getName() << ", signed: " << obj.isSigned();
    os << " ,required sign grade: " << obj.getRequiredSignGrade();
    os << " ,required exec grade: " << obj.getRequiredExecGrade();
    return (os);
}
