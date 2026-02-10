#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal type") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;

}

WrongAnimal::WrongAnimal(std::string new_type) : type(new_type) {
    std::cout << "WrongAnimal new_type constructor called" << std::endl;

}

WrongAnimal::WrongAnimal(const WrongAnimal &obj): type(obj.type) {
    std::cout << "WrongAnimal object constructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal equal operator called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "WrongAnimal sound" << std::endl;
}