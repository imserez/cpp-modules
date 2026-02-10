#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main (void) {

    FragTrap frank("Frank");
    frank.highFivesGuys();
    ClapTrap givela("Givela");

    std::cout << " ----------------------------------- " << std::endl;

    frank.attack(givela.getName());
    givela.takeDamage(frank.getDamage());

    std::cout << " ----------------------------------- " << std::endl;

    givela.attack(frank.getName());
    frank.takeDamage(givela.getDamage());

    std::cout << " ----------------------------------- " << std::endl;

    FragTrap lewis;
    FragTrap pepe(frank);

    pepe.highFivesGuys();

    std::cout << " ----------------------------------- " << std::endl;

    return (0);
}