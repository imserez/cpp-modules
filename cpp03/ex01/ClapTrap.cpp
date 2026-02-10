#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string new_name) : name(new_name), 
    hitPoints(10), energyPoints(10), attackDamage(0) {

        std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap() : name("unnamed"), 
    hitPoints(10), energyPoints(10), attackDamage(0) {

        std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap destructor called" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap &obj) : name(obj.getName()), hitPoints(obj.getHitPoints()),
    energyPoints(obj.getEnergyPoints()), attackDamage(obj.getDamage())
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.getName();
        this->hitPoints = obj.getHitPoints();
        this->energyPoints = obj.getEnergyPoints();
        this->attackDamage = obj.getDamage();
    }
    return (*this);
}

int ClapTrap::getEnergyPoints(void) const
{
    return this->energyPoints;
}

int ClapTrap::getHitPoints(void) const
{
    return this->hitPoints;
}

int ClapTrap::getDamage(void) const
{
    return this->attackDamage;
}

std::string ClapTrap::getName(void) const
{
    return this->name;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->getName() << " has been attacked, receiving ";
    std::cout << amount << " points of damage!" << std::endl; 
    std::cout << "ClapTrap " << this->getName() << " now has ";
    
    if (amount >= (unsigned int)this->getHitPoints())
    {
        this->hitPoints = 0;
        std::cout << this->getHitPoints() << " hit points!" << std::endl;
    }
    else
    {
        this->hitPoints -= amount;
        std::cout << (int)(this->getHitPoints()) << " hit points!" << std::endl;
    }        
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
    {
        this->energyPoints--;
        std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing ";
        std::cout << this->getDamage() << " points of damage!" << std::endl; 
        std::cout << "ClapTrap " << this->getName() << " now has " << this->getEnergyPoints() << " energy points." << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->getName() << " has no energy or hit points." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
    {
        this->energyPoints--;
        this->hitPoints += amount;
        std::cout << "ClapTrap " << this->getName() << " repairs itelf with " << amount << " points" << std::endl;
        std::cout << "ClapTrap " << this->getName() << " now has ";
        std::cout << this->getHitPoints() << " hit points!" << std::endl;
        std::cout << "ClapTrap " << this->getName() << " now has " << this->getEnergyPoints() << " energy points." << std::endl;

    }
    else
        std::cout << "ClapTrap " << this->getName() << " has no energy or hit points." << std::endl;
}