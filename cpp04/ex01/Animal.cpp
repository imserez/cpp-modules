#include "Animal.hpp"

Animal::Animal() : type("Animal type") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;

}

Animal::Animal(std::string new_type) : type(new_type) {
    std::cout << "Animal new_type constructor called" << std::endl;

}

Animal::Animal(const Animal &obj): type(obj.type) {
    std::cout << "Animal object constructor called" << std::endl;
}

std::string Animal::getType(void) const
{
    return type;
}

Animal& Animal::operator=(const Animal &obj)
{
    std::cout << "Animal equal operator called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

void Animal::makeSound(void) const {
    std::cout << "Animal sound" << std::endl;
}