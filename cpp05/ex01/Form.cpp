#include "Form.hpp"

#include <exception>
#include <ostream>

class Bureaucrat;

Form::Form() : _name("unnamed form"), _signed(0), _requiredSignGrade(1), _requiredExecGrade(1) {};

Form::Form(std::string name) : _name(name), _signed(0), _requiredSignGrade(1), _requiredExecGrade(1) {};

Form::Form(std::string name, int requiredSignGrade, int requiredExecGrade) : _name(name),
    _signed(0),
    _requiredSignGrade(requiredSignGrade),
    _requiredExecGrade(requiredExecGrade)
{
    checkGrade(requiredSignGrade);
    checkGrade(requiredExecGrade);
}

Form::~Form() {};

Form::Form(const Form &obj) : _name(obj.getName()),
    _signed(obj.isSigned()),
    _requiredSignGrade(obj.getRequiredSignGrade()),
   _requiredExecGrade(obj.getRequiredExecGrade())
{
    checkGrade(obj.getRequiredSignGrade());
    checkGrade(obj.getRequiredExecGrade());
}

Form& Form::operator=(const Form &obj)
{
    if (this != &obj)
    {
        _signed = obj.isSigned();
    }
    return *this;
}

bool  Form::isSigned(void) const
{
    return _signed;
}

void  Form::checkGrade(const int grade)
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    else if (grade > 150)
        throw Form::GradeTooLowException();
}

bool Form::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() > this->_requiredSignGrade)
        throw Form::GradeTooLowException();
    else
    {
        _signed = true;
        return true;
    }
    return false;
}

std::string Form::getName(void) const
{
    return this->_name;
}

int   Form::getRequiredSignGrade(void) const
{
    return _requiredSignGrade;
}
int   Form::getRequiredExecGrade(void) const
{
    return _requiredExecGrade;
}

std::ostream& operator<<(std::ostream &os, const Form &obj)
{
    os << obj.getName() << ", signed: " << obj.isSigned();
    os << " ,required sign grade: " << obj.getRequiredSignGrade();
    os << " ,required exec grade: " << obj.getRequiredExecGrade();
    return (os);
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form exception: Grade is too high";
}

std::string Form::GradeTooHighException::details(const int value) const {
    std::ostringstream oss;
    oss << "Grade " << value << " is too high for this form.";
    return oss.str();
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form exception: Grade is too low";
}

std::string Form::GradeTooLowException::details(const int value) const {
    std::ostringstream oss;
    oss << "Grade " << value << " is too low for this form.";
    return oss.str();
}
