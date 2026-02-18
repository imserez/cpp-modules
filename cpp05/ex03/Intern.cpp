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
        
AForm* Intern::makeForm(std::string formName, std::string targetForm)
{
    int i = 0;
    std::string options[] = { "robotomy request", "presidential request", "shrubbery request"};
    while (i < 3 && options[i] != formName)
        i++;
    
    switch(i)
    {

        case 0:
            return new RobotomyRequestForm(targetForm);
            break;
        case 1:
            return new PresidentialPardonForm(targetForm);
            break;
        case 2:
            return new ShrubberyCreationForm(targetForm);
            break;
        default:
            throw Intern::InvalidName();
    }
}