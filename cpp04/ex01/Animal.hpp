#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
class   Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string new_type);
        Animal(const Animal &obj);
        virtual ~Animal();
        Animal& operator=(const Animal &obj);
        std::string getType(void) const;
        virtual void    makeSound(void) const;
};

#endif