#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <exception>
#include <ostream>

Bureaucrat::Bureaucrat() : _name("unnamed Bureaucrat"), _grade(150) {};

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {};

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(150)
{
    this->setGrade(grade);
}

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj.getName()), _grade(obj.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
    {
        setGrade(obj.getGrade());
    }
    return *this;
}

void    Bureaucrat::incrementGrade(void)
{
    this->setGrade(this->getGrade() - 1);
}
void    Bureaucrat::decrementGrade(void)
{
    this->setGrade(this->getGrade() + 1);
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
}

std::string Bureaucrat::getName(void) const
{
    return this->_name;
}
int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << ", grade " << obj.getGrade();
    return (os);
}
void    Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (const AForm::GradeTooHighException& e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName();
        std::cout << " because: " << e.what() << std::endl;
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName();
        std::cout << " because: " << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName();
        std::cout << " because: " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Exception value too high";
}

std::string const Bureaucrat::GradeTooHighException::details(const int value) const throw()
{
    std::ostringstream oss;
    oss << "The value: " << value << " is too high!";
    return oss.str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Exception value too low";
}

std::string const Bureaucrat::GradeTooLowException::details(const int value) const throw()
{
    std::ostringstream oss;
    oss << "The value: " << value << " is too low!";
    return oss.str();
}