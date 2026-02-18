#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

class Form {
  private:
    const std::string _name;
    bool        _signed;
    const   int _requiredSignGrade;
    const   int _requiredExecGrade;
  public:
  Form();
  Form(std::string name);
  Form(std::string name, int requiredSignGrade, int requiredExecGrade);
  ~Form();
  Form(const Form &obj);
  Form& operator=(const Form &obj);

    class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
                std::string details(const int value) const; // Quitamos throw() aquí por seguridad con string
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
                std::string details(const int value) const;
        };

  std::string getName(void) const;

  void  checkGrade(const int grade);

  bool  isSigned(void) const;
  int   getRequiredSignGrade(void) const;
  int   getRequiredExecGrade(void) const;
  bool  beSigned(const Bureaucrat &obj);
};

std::ostream& operator<<(std::ostream &os, const Form &obj);
