#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void)
{

    Animal* animals[NIDEAS];

    for(int i = 0, j=NIDEAS-1; i < NIDEAS/2; i++, j--)
    {
        animals[i] = new Dog();
        animals[j] = new Cat();
    }

    for(int i = 0; i<NIDEAS; i++)
    {
        std::cout << "["<< i << "] : ";
        delete animals[i];
        std::cout << std::endl;
    }

    std::cout << " ----------------------------------- " << std::endl;
    Dog doggy;
    {
        std::cout << " ..... " << std::endl;
        Dog flanders = doggy;
        std::cout << " ..... " << std::endl;
    }
    std::cout << " ..... " << std::endl;
    std::cout << " ----------------------------------- " << std::endl;

    return 0;

}