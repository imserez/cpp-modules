#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void)
{

    AAnimal* AAnimals[NIDEAS];

    for(int i = 0, j=NIDEAS-1; i < NIDEAS/2; i++, j--)
    {
        AAnimals[i] = new Dog();
        AAnimals[j] = new Cat();
    }

    for(int i = 0; i<NIDEAS; i++)
    {
        std::cout << "["<< i << "] : ";
        delete AAnimals[i];
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

    // AAnimal juancarlos = new AAnimal();
    // delete juancarlos;

    std::cout << " ----------------------------------- " << std::endl;


    return 0;

}