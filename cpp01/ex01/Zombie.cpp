#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << this->getName() << ": has been destroyed." << std::endl;
};

void Zombie::announce(void)
{
    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName(void)
{
    return name;
}

Zombie *newZombie(std::string name)
{
    return new Zombie(name);
}

void    Zombie::setName(std::string new_name)
{
    name = new_name;
}