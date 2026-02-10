#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain *brain;
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog &obj);
        ~Dog();
        Dog &operator=(const Dog &obj);
        void    makeSound(void) const;

};

#endif // dog_hpp