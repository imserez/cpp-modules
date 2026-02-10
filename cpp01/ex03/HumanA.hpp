#ifndef HUMAN_A_H
# define HUMAN_A_H

# include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon &_dangerousItem;
    public:
        HumanA(std::string name, Weapon &newWeapon);
        ~HumanA();
        void attack(void);
        const std::string& getName(void) const;
        Weapon& getWeapon(void);
};

#endif // human_a_h