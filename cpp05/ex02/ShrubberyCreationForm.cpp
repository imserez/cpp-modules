#include "ShrubberyCreationForm.hpp"

#include <exception>
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>

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

void  ShrubberyCreationForm::executeAction(std::string bureucratName) const
{
    std::ofstream file((this->getTarget() + std::string("_shrubbery")).c_str());

    if (file)
    {
        file << "   *   \n";
        file << "  ***  \n";
        file << " ***** \n";
        file << "   '   \n";
        file.close();
        std::cout << bureucratName << " executed " << this->getName() << std::endl;
    }
    else
        throw ShrubberyCreationForm::ErrorOpeningFileException();
}


std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &obj)
{
    os << obj.getName() << ", signed: " << obj.isSigned();
    os << " ,required sign grade: " << obj.getRequiredSignGrade();
    os << " ,required exec grade: " << obj.getRequiredExecGrade();
    return (os);
}

const char* ShrubberyCreationForm::ErrorOpeningFileException::what() const throw() {
    return "Shrubbery exception: Cannot open file";
}