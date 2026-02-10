#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj.type) {
    std::cout << "WrongCat type constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << "WrongCat parameterized constructor called" << std::endl;
    this->type = type;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
    std::cout << "WrongCat equal operator called" << std::endl;
    if (this != &obj)
    {
        WrongAnimal::operator=(obj);
    }
    return *this;
}

void    WrongCat::makeSound(void) const {
    std::cout << "Meow wrong" << std::endl;
}