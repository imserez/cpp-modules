#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat jimmy("Jimmy", 20);
        std::cout << jimmy << std::endl;

        std::cout << "-------------------------------------" << std::endl;


        std::cout << "-------------------------------------" << std::endl;

        jimmy.incrementGrade();
        std::cout << jimmy << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    // int val = 160;
    // try
    // {
    //     AForm invalideo("invalideo", val, val);
    // }
    // catch (const AForm::GradeTooHighException& e)
    // {
    //     std::cout << "Exception handled: " << e.what() << std::endl;
    //     std::cout << "Details: " << e.details(val) << std::endl;
    // }
    // catch (const AForm::GradeTooLowException& e)
    // {
    //     std::cout << "Exception handled: " << e.what() << std::endl;
    //     std::cout << "Details: " << e.details(val) << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << "Unexpected exception caught: " << e.what() << std::endl;
    // }

    return (0);
}