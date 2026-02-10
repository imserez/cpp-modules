#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void) {

    ScavTrap frank("Frank");
    frank.guardGate();
    ClapTrap givela("Givela");

    std::cout << " ----------------------------------- " << std::endl;

    frank.attack(givela.getName());
    givela.takeDamage(frank.getDamage());

    std::cout << " ----------------------------------- " << std::endl;

    givela.attack(frank.getName());
    frank.takeDamage(givela.getDamage());

    std::cout << " ----------------------------------- " << std::endl;

    ScavTrap lewis;
    ScavTrap pepe(frank);

    pepe.guardGate();

    std::cout << " ----------------------------------- " << std::endl;

    return (0);
}