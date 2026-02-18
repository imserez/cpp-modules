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
};

std::ostream& operator<<(std::ostream &os, const AForm &obj);
