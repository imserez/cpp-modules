#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>
class   AAnimal {
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(std::string new_type);
        AAnimal(const AAnimal &obj);
        virtual ~AAnimal() = 0;
        AAnimal& operator=(const AAnimal &obj);
        std::string getType(void) const;
        virtual void    makeSound(void) const = 0;
};

#endif