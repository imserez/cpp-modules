#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


static void    shruberry_tests();
static void    robo_tests();
static void    president_tests();

int main(void)
{
    std::cout       << "*******************************************************" << std::endl;
    std::cout       << "***************** > SHRUBERRY TESTS < *****************" << std::endl;
    std::cout       << "*******************************************************" << std::endl << std::endl;

    shruberry_tests();

    std::cout       << "*******************************************************" << std::endl;

    std::cout       << "*******************************************************" << std::endl;
    std::cout       << "******************* > ROBO TESTS < ********************" << std::endl;
    std::cout       << "*******************************************************" << std::endl << std::endl;

    robo_tests();

    std::cout       << "*******************************************************" << std::endl;

    std::cout       << "*******************************************************" << std::endl;
    std::cout       << "******************* > PRESI TESTS < *******************" << std::endl;
    std::cout       << "*******************************************************" << std::endl << std::endl;

    president_tests();

    std::cout       << "*******************************************************" << std::endl;


    return (0);
}



static void    shruberry_tests()
{
    ShrubberyCreationForm form_shrubbery("hola");
    Bureaucrat jimmy("Jimmy", 20);

    //  ######### ERROR : THE FORM IS NOT SIGNED
    try
    {
        form_shrubbery.execute(jimmy);
        std::cout << "...." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    jimmy.setGrade(146);
     //  ######### ERROR  : THE SIGN GRADE IS 146, MINIMUM IS 137
    try
    {
        jimmy.signForm(form_shrubbery);
        form_shrubbery.execute(jimmy);
        std::cout << "...." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    jimmy.setGrade(20);
    //  ######### VALID : THE GRADE IS OK and FORM IS SIGNED
    try
    {
        jimmy.signForm(form_shrubbery);
        form_shrubbery.execute(jimmy);
        std::cout << "...." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    jimmy.setGrade(138);

    //  ######### ERROR  : THE EXEC GRADE IS 138, MINIMUM IS 137
    try
    {
        form_shrubbery.execute(jimmy);
        std::cout << "...." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

}

static void    robo_tests()
{
    RobotomyRequestForm form_robo("hola");
    Bureaucrat claudio("Claudio", 20);

    //  ######### ERROR : THE FORM IS NOT SIGNED
    try
    {
        form_robo.execute(claudio);
        std::cout << "...." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    claudio.setGrade(146);
     //  ######### ERROR  : THE SIGN GRADE IS 146, MINIMUM IS 72
    try
    {
        claudio.signForm(form_robo);
        form_robo.execute(claudio);
        std::cout << "...." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    claudio.setGrade(20);
    //  ######### VALID : THE GRADE IS OK and FORM IS SIGNED
    try
    {
        claudio.signForm(form_robo);
        form_robo.execute(claudio);
        std::cout << "...." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    claudio.setGrade(138);

    //  ######### ERROR  : THE EXEC GRADE IS 138, MINIMUM IS 45
    try
    {
        form_robo.execute(claudio);
        std::cout << "...." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

}

static void    president_tests()
{
    PresidentialPardonForm form_presi("hola");
    Bureaucrat federico("Federico", 20);

    //  ######### ERROR : THE FORM IS NOT SIGNED
    try
    {
        form_presi.execute(federico);
        std::cout << "...." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    federico.setGrade(146);
     //  ######### ERROR  : THE SIGN GRADE IS 146, MINIMUM IS 25
    try
    {
        federico.signForm(form_presi);
        form_presi.execute(federico);
        std::cout << "...." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    federico.setGrade(3);
    //  ######### VALID : THE GRADE IS OK and FORM IS SIGNED
    try
    {
        federico.signForm(form_presi);
        form_presi.execute(federico);
        std::cout << "...." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

    federico.setGrade(138);

    //  ######### ERROR  : THE EXEC GRADE IS 138, MINIMUM IS 5
    try
    {
        form_presi.execute(federico);
        std::cout << "...." << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;

}