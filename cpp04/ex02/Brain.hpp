#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

#define NIDEAS 100

class Brain {
    private:
        std::string ideas[NIDEAS];
    public:
        Brain();
        Brain(const Brain &obj);
        ~Brain();
        Brain(const std::string *new_ideas);
        Brain& operator=(const Brain &obj);
};

#endif