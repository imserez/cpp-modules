#include "Zombie.hpp"

Zombie::Zombie(void) {};
Zombie::Zombie(std::string name) : name(name) {}

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