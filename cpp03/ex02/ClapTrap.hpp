#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
    protected:
        std::string name;
        int         hitPoints;
        int         energyPoints;
        int         attackDamage;
    public:
        ClapTrap(std::string new_name);
        ClapTrap();
        virtual ~ClapTrap();
        ClapTrap(const ClapTrap &obj);

        ClapTrap &operator=(const ClapTrap &obj);

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        std::string getName(void) const;
        int         getDamage(void) const;
        int         getHitPoints(void) const;
        int         getEnergyPoints(void) const;

};
#endif // #ifndef CLAPTRAP_HPP