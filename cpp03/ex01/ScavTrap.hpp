#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    private:

    public:
        ScavTrap(std::string new_name);
        ScavTrap(const ScavTrap &obj);
        ScavTrap();
        ~ScavTrap();
        void    attack(const std::string &target);
        void    guardGate(void);
        ScavTrap &operator=(const ScavTrap &obj);
};

#endif