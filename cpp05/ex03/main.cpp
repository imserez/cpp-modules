#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main(void)
{
    std::cout       << "*******************************************************" << std::endl;
    {
        try
        {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
            std::cout << rrf->getName() << "created successfully!" << std::endl;
            delete rrf;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout       << "*******************************************************" << std::endl;
    {
        try
        {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("presidential request", "Bender");
            std::cout << rrf->getName() << "created successfully!" << std::endl;
            delete rrf;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout       << "*******************************************************" << std::endl;
    {
        try
        {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
            std::cout << rrf->getName() << "created successfully!" << std::endl;
            delete rrf;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout       << "*******************************************************" << std::endl;
     {
        try
        {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("francisco request", "Bender");
            std::cout << rrf->getName() << "created successfully!" << std::endl;
            delete rrf;
        }
        catch (Intern::InvalidName &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
            std::cout << "Exception details: " << e.details("francisco") << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout       << "*******************************************************" << std::endl;
    return (0);
}