#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

class RobotomyRequestForm : public AForm {
  private:
    const std::string _target;
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &obj);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &obj);

    void executeAction(std::string bureucratName) const;
    std::string getTarget(void) const;

    class RobotizationFailedException : public std::exception {
        public:
            virtual const char* what() const throw()
            {
                return "Exception robotization failed!";
            }
    };
};

std::ostream& operator<<(std::ostream &os, const AForm &obj);
