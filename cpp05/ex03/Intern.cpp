#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

Intern::Intern() {};
Intern::~Intern() {};
Intern::Intern(const Intern &obj) { (void) obj; };

Intern& Intern::operator=(const Intern &obj)
{
    (void) obj;
    return *this;
}

AForm* Intern::makeRobotomy(const std::string target) 
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(const std::string target) 
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeShrubbery(const std::string target) 
{
    return new ShrubberyCreationForm(target);
}


AForm* Intern::makeForm(std::string formName, std::string target) {
    
    std::string levels[] = {
        "robotomy request",
        "presidential request",
        "shrubbery request"
    };

    AForm* (*creators[])(const std::string) = {
        &Intern::makeRobotomy,
        &Intern::makePresidential,
        &Intern::makeShrubbery
    };

    for (int i = 0; i < 3; i++) {
        if (formName == levels[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (creators[i](target));
        }
    }
    throw Intern::InvalidNameException();
}