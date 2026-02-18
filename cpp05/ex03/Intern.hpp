#pragma once

# include <iostream>
# include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    private:
        static AForm* makeRobotomy(const std::string target);
        static AForm* makePresidential(const std::string target);
        static AForm* makeShrubbery(const std::string target);
    public:
        Intern();
        ~Intern();
        Intern(const Intern &obj);
        Intern& operator=(const Intern &obj);
        
        AForm* makeForm(std::string formName, std::string targetForm);
    
    class InvalidNameException : public std::exception {
        public:
            virtual const char* what() const throw();
            std::string const details(const std::string value) const throw();
    };
};