#include "Bureaucrat.hpp"


int main(void)
{

    Bureaucrat jimmy("Jimmy");
    std::cout << jimmy << std::endl;

    std::cout << "-------------------------------------" << std::endl;

    try {
        jimmy.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Exception handled: " << e.what() << std::endl;
        std::cout << "Details: " << e.details(jimmy.getGrade()) << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Exception handled: " << e.what() << std::endl;
        std::cout << "Details: " << e.details(jimmy.getGrade()) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    try {
        jimmy.decrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Exception handled: " << e.what() << std::endl;
        std::cout << "Details: " << e.details(jimmy.getGrade()) << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Exception handled: " << e.what() << std::endl;
        std::cout << "Details: " << e.details(jimmy.getGrade()) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << jimmy << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    int init = 160;
    try {

        Bureaucrat petro("Petro", 160);
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Exception handled: " << e.what() << std::endl;
        std::cout << "Details: " << e.details(init) << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Exception handled: " << e.what() << std::endl;
        std::cout << "Details: " << e.details(init) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    init = 0;
    try {
        Bureaucrat javixu("Javixu", 0);

    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Exception handled: " << e.what() << std::endl;
        std::cout << "Details: " << e.details(init) << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Exception handled: " << e.what() << std::endl;
        std::cout << "Details: " << e.details(init) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "-------------------------------------" << std::endl;

    Bureaucrat kiko("kiko", 1);
    std::cout << kiko << std::endl;
    std::cout << "-------------------------------------" << std::endl;


    try {
        kiko.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Exception handled: " << e.what() << std::endl;
        std::cout << "Details: " << e.details(kiko.getGrade()) << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Exception handled: " << e.what() << std::endl;
        std::cout << "Details: " << e.details(kiko.getGrade()) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }





    std::cout << kiko << std::endl;
}
