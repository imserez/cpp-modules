#include "Animal.hpp"
#include "Dog.hpp"


Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(obj.type) {
    std::cout << "Dog type constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog parameterized constructor called" << std::endl;
    this->type = type;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &obj)
{
    std::cout << "Dog equal operator called" << std::endl;
    if (this != &obj)
    {
        Animal::operator=(obj);
    }
    return *this;
}

void    Dog::makeSound(void) const {
    std::cout << "Bark" << std::endl;
}
