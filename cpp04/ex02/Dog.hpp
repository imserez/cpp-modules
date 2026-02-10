#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
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