#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    private:

    public:
        FragTrap(std::string new_name);
        FragTrap(const FragTrap &obj);
        FragTrap();
        ~FragTrap();
        void    highFivesGuys(void);
        FragTrap &operator=(const FragTrap &obj);
};

#endif // FRAGTRAP_HPP