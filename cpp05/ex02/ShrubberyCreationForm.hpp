#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

class ShrubberyCreationForm : public AForm {
  private:
    const std::string _target;
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &obj);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &obj);

    void executeAction(void);
    std::string getTarget(void) const;
};

std::ostream& operator<<(std::ostream &os, const AForm &obj);
