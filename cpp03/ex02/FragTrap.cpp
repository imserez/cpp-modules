#include "FragTrap.hpp"

FragTrap::FragTrap(std::string new_name) : ClapTrap(new_name) {

    std::cout << "FragTrap string constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap() : ClapTrap() {

    std::cout << "FragTrap default constructor called" << std::endl;
    this->name = "unnamed";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj) {

    std::cout << "FragTrap copy constructor called" << std::endl;
    this->name = obj.getName();
    this->hitPoints = obj.getHitPoints();
    this->energyPoints = obj.getEnergyPoints();
    this->attackDamage = obj.getDamage();
}

FragTrap& FragTrap::operator=(const FragTrap &obj)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.getName();
        this->hitPoints = obj.getHitPoints();
        this->energyPoints = obj.getEnergyPoints();
        this->attackDamage = obj.getDamage();
    }
    return (*this);
}

void    FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->getName() << " politely requests a high-fives." << std::endl;
}