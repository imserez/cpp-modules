#include "Zombie.hpp"

int main(void)
{
    Zombie *memZombie = newZombie("Rodolfo");
    memZombie->announce();
    delete memZombie;

    randomChump("Kiko");
    return 0;
}