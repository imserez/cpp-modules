#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &newWeapon) : _name(name), _dangerousItem(newWeapon) {}
HumanA::~HumanA() {}

const std::string& HumanA::getName(void) const
{
    return _name;
}

Weapon& HumanA::getWeapon(void)
{
    return _dangerousItem;
}

void HumanA::attack(void)
{
    std::cout << getName() << " attacks with their " << getWeapon().getType() << std::endl;
}