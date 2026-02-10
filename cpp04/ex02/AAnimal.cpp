#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal type") {
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;

}

AAnimal::AAnimal(std::string new_type) : type(new_type) {
    std::cout << "AAnimal new_type constructor called" << std::endl;

}

AAnimal::AAnimal(const AAnimal &obj): type(obj.type) {
    std::cout << "AAnimal object constructor called" << std::endl;
}

std::string AAnimal::getType(void) const
{
    return type;
}

AAnimal& AAnimal::operator=(const AAnimal &obj)
{
    std::cout << "AAnimal equal operator called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}