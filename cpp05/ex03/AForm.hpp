#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

class AForm {

  private:

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
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class NotSignedFormException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    std::string getName(void) const;

    void  checkGrade(const int grade);

    bool  isSigned(void) const;
    int   getRequiredSignGrade(void) const;
    int   getRequiredExecGrade(void) const;
    bool  beSigned(const Bureaucrat &obj);

    void execute(Bureaucrat const & executor) const;
    virtual void executeAction(std::string bureaucratName) const = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm &obj);
