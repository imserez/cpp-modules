#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    {
        Weapon  club = Weapon("crude spiked club");

        HumanA  bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon  club = Weapon("crude spiked club");

        HumanB  jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    {
        HumanB  naked("Naked");
        naked.attack();
        
        Weapon  club = Weapon("now with crude spiked club");
        naked.setWeapon(club);
        naked.attack();
    }
    return (0);
}