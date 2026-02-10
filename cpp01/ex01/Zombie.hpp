#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie(void);
        std::string getName(void);
        void setName(std::string new_name);
        void announce(void);
};

Zombie *newZombie(std::string name);
Zombie *zombieHorde(int N, std::string name);

#endif