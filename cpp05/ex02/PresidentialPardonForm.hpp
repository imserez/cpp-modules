#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

class PresidentialPardonForm : public AForm {
  private:
    const std::string _target;
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &obj);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &obj);

    void executeAction(std::string bureucratName) const;
    std::string getTarget(void) const;

    class RobotizationFailedException : public std::exception {
        public:
            virtual const char* what() const throw()
            {
                return "Exception PresidentialPardonForm failed!";
            }
    };
};

std::ostream& operator<<(std::ostream &os, const AForm &obj);
