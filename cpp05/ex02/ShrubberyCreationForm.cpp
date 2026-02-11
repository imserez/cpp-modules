#include "ShrubberyCreationForm.hpp"

#include <exception>
#include <ostream>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("unnamed Shruberry", 145, 137) {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shruberry", 145, 137), _target(target) {};

ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
    : AForm(obj), _target(obj.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    if (this != &obj)
    {
        _signed = obj.isSigned();
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
  return this->_target;
}

void  ShrubberyCreationForm::executeAction(void)
{
    try {
        std::ofstream file(this->getTarget());

        if (file)
        {
            file << "   *   \n";
            file << "  ***  \n";
            file << " ***** \n";
            file << "   '   \n";

            file.close();
        }
        else
            throw AForm::ErrorOpeningFileException();

    } catch (const  AForm::ErrorOpeningFileException &e){
        std::cout << this->getName() << " couldn't execute " << this->getName();
        std::cout << " because: " << e.what() << std::endl;
        std::cout << " details: " << e.details(this->getTarget()) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't execute " << this->getName();
        std::cout << " because: " << e.what() << std::endl;
    }
}


std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &obj)
{
    os << obj.getName() << ", signed: " << obj.isSigned();
    os << " ,required sign grade: " << obj.getRequiredSignGrade();
    os << " ,required exec grade: " << obj.getRequiredExecGrade();
    return (os);
}
