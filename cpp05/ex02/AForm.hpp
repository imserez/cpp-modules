#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

class AForm {
  protected:
    const std::string _name;
    bool        _signed;
    const   int _requiredSignGrade;
    const   int _requiredExecGrade;
  public:
    AForm();
    AForm(std::string name);
    AForm(std::string name, int requiredSignGrade, int requiredExecGrade);
    virtual ~AForm() = 0;
    AForm(const AForm &obj);
    AForm& operator=(const AForm &obj);

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw()
            {
                return "Exception value too high";
            }

            std::string const details(const int value) const throw()
            {
                std::ostringstream oss;
                oss << "The value: " << value << " is too high!";
                return oss.str();
            }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw()
            {
                return "Exception value too low";
            }

            std::string const details(const int value) const throw()
            {
                std::ostringstream oss;
                oss << "The value: " << value << " is too low!";
                return oss.str();
            }
    };

    class NotSignedFormException : public std::exception {
        public:
            virtual const char* what() const throw()
            {
                return "Exception form not signed";
            }

            std::string const details(std::string name) const throw()
            {
                std::ostringstream oss;
                oss << "The form: " << name << " is not signed!";
                return oss.str();
            }
    };

    std::string getName(void) const;

    void  checkGrade(const int grade);

    bool  isSigned(void) const;
    int   getRequiredSignGrade(void) const;
    int   getRequiredExecGrade(void) const;
    bool  beSigned(const Bureaucrat &obj);

    void execute(Bureaucrat const & executor);
    virtual void executeAction() = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm &obj);
