#include "ClapTrap.hpp"


int main (void) {

    ClapTrap robert("Robert");
    ClapTrap gilbert("Gilbert");

    std::cout << " ----------------------------------- " << std::endl;

    robert.attack(gilbert.getName());
    gilbert.takeDamage(robert.getDamage());

    std::cout << " ----------------------------------- " << std::endl;
    
    robert.beRepaired(4);
    gilbert.beRepaired(2);

    std::cout << " ----------------------------------- " << std::endl;
    
    ClapTrap unnamed;
    unnamed.attack(robert.getName());
    robert.takeDamage(unnamed.getDamage());
    
    std::cout << " ----------------------------------- " << std::endl;

    return (0);
}