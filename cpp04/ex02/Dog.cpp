#include "AAnimal.hpp"
#include "Dog.hpp"

#include "Brain.hpp"

Dog::Dog() : AAnimal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &obj) : AAnimal(obj.type) {
    std::cout << "Dog type constructor called" << std::endl;
    this->brain = new Brain(*obj.brain);
}

Dog::Dog(std::string type) : AAnimal(type)
{
    std::cout << "Dog parameterized constructor called" << std::endl;
    this->type = type;
    this->brain = new Brain();
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

Dog& Dog::operator=(const Dog &obj)
{
    std::cout << "Dog equal operator called" << std::endl;
    if (this != &obj)
    {
        AAnimal::operator=(obj);
        *this->brain = *obj.brain;
    }
    return *this;
}

void    Dog::makeSound(void) const {
    std::cout << "Bark" << std::endl;
}
