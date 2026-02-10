#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i<NIDEAS; i++)
    {
        ideas[i] = obj.ideas[i];
    }
}


Brain::Brain(const std::string *new_ideas)
{
    std::cout << "Brain ideas constructor called" << std::endl;
    for (int i = 0; i<NIDEAS; i++)
    {
        ideas[i] = new_ideas[i];
    }
}

Brain& Brain::operator=(const Brain &obj)
{
    std::cout << "Brain equal operator called" << std::endl;
    if (this != &obj)
    {
        for (int i = 0; i<NIDEAS; i++)
        {
            this->ideas[i] = obj.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}