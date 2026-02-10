#include "Animal.hpp"
#include "Cat.hpp"


Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(obj.type) {
    std::cout << "Cat type constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat parameterized constructor called" << std::endl;
    this->type = type;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
    std::cout << "Cat equal operator called" << std::endl;
    if (this != &obj)
    {
        Animal::operator=(obj);
    }
    return *this;
}

void    Cat::makeSound(void) const {
    std::cout << "Meow" << std::endl;
}