#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name), _dangerousItem(NULL) {}
HumanB::~HumanB() {}

const std::string& HumanB::getName(void) const
{
    return _name;
}

void HumanB::setWeapon(Weapon &new_weapon)
{
    _dangerousItem = &new_weapon;
}

Weapon* HumanB::getWeapon(void)
{
    return _dangerousItem;
}

void HumanB::attack(void)
{
    if (getWeapon() == NULL)
    {
        std::cout << getName() << " attacks without weapon " << std::endl;
    }
    else
        std::cout << getName() << " attacks with their " << getWeapon()->getType() << std::endl;
}