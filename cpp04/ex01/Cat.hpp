#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *brain;
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat &obj);
        ~Cat();
        Cat &operator=(const Cat &obj);
        void    makeSound(void) const;

};

#endif // CAT_HPP