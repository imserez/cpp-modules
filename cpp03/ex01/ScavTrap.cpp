#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string new_name) : ClapTrap(new_name) {

    std::cout << "ScavTrap string constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap() : ClapTrap() {

    std::cout << "ScavTrap default constructor called" << std::endl;
    this->name = "unnamed";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj) {

    std::cout << "ScavTrap copy constructor called" << std::endl;
    this->hitPoints = obj.getHitPoints();
    this->energyPoints = obj.getEnergyPoints();
    this->attackDamage = obj.getDamage();
    this->name = obj.getName();
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.getName();
        this->hitPoints = obj.getHitPoints();
        this->energyPoints = obj.getEnergyPoints();
        this->attackDamage = obj.getDamage();
    }
    return (*this);
}

void    ScavTrap::attack(const std::string &target)
{
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
    {
        this->energyPoints--;
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing ";
        std::cout << this->getDamage() << " points of damage!" << std::endl; 
        std::cout << "ScavTrap " << this->getName() << " now has " << this->getEnergyPoints() << " energy points." << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->getName() << " has no energy or hit points." << std::endl;
}

void    ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->getName() << " is now in Gate Keeper mode." << std::endl;
}