#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat jimmy("Jimmy", 20);
        std::cout << jimmy << std::endl;

        Form elFormas("el Formas", 25, 25);
        std::cout << elFormas << std::endl;

        jimmy.signForm(elFormas);
        std::cout << elFormas << std::endl;
        std::cout << "-------------------------------------" << std::endl;

        Form torito("el torito", 19, 19);
        std::cout << torito << std::endl;

        jimmy.signForm(torito);
        std::cout << "-------------------------------------" << std::endl;

        jimmy.incrementGrade();
        std::cout << jimmy << std::endl;

        jimmy.signForm(torito);
        std::cout << torito << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    int val = 160;
    try
    {
        Form invalideo("invalideo", val, val);
    }
    catch (const Form::GradeTooHighException& e)
    {
        std::cout << "Exception handled: " << e.what() << std::endl;
        std::cout << "Details: " << e.details(val) << std::endl;
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cout << "Exception handled: " << e.what() << std::endl;
        std::cout << "Details: " << e.details(val) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception caught: " << e.what() << std::endl;
    }

    return (0);
}