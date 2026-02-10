#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include <string>
#include <sstream>

class Bureaucrat {

  private:
    const std::string   _name;
    int        _grade;
  public:
    Bureaucrat();
    Bureaucrat(std::string name);
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat& operator=(const Bureaucrat &obj);

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

    std::string getName(void) const;
    int getGrade(void) const;
    void    setGrade(int grade);

    void    incrementGrade(void);
    void    decrementGrade(void);

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj);
