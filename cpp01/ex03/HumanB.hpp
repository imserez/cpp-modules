#ifndef HUMAN_B_H
# define HUMAN_B_H

# include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon *_dangerousItem;
    public:
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon &newWeapon);
        void attack(void);
        const std::string& getName(void) const;
        Weapon *getWeapon(void);
};

#endif // human_b_h