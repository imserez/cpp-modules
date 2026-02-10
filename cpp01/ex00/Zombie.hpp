#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
    public:
        Zombie(void);
        ~Zombie();
        Zombie (std::string name);

        void announce(void);
        std::string getName(void);
    private:
        std::string name;
};
Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif // zombie_h