#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat &obj);
        ~WrongCat();
        WrongCat &operator=(const WrongCat &obj);
        void    makeSound(void) const;

};


#endif // WRONG_CAT_HPP