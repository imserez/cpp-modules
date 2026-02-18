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

    void executeAction(std::string bureucratName);
    std::string getTarget(void) const;

    class ErrorOpeningFileException : public std::exception {
        public:
            virtual const char* what() const throw()
            {
                return "Exception error opening the file";
            }

            std::string const details(std::string filename) const throw()
            {
                std::ostringstream oss;
                oss << "Error opening the file: " << filename;
                return oss.str();
            }
    };
};

std::ostream& operator<<(std::ostream &os, const AForm &obj);
