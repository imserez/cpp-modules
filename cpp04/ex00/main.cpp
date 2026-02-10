#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void)
{
    const Animal *meta  = new Animal();
    const Animal *j     = new Dog();
    const Animal *i     = new Cat();

    const WrongAnimal *z = new WrongAnimal();
    const WrongAnimal *u = new WrongCat();


    std::cout << " ----------------------------------- " << std::endl;

    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    meta->makeSound();
    j->makeSound();
    i->makeSound();

    std::cout << " ----------------------------------- " << std::endl;

    std::cout << z->getType() << " " << std::endl;
    std::cout << u->getType() << " " << std::endl;
    z->makeSound();
    u->makeSound();

    std::cout << " ----------------------------------- " << std::endl;


    const Animal *meta2  = new Animal(*meta);
    const Dog *j2     = new Dog();
    const Dog *j3     = new Dog(*j2);

    std::cout << " ----------------------------------- " << std::endl;

    meta2->makeSound();
    j2->makeSound();
    j3->makeSound();


    std::cout << " ----------------------------------- " << std::endl;

    delete meta;
    delete j;
    delete meta2;
    delete j2;
    delete j3;

    delete z;

    std::cout << " ----------------------------------- " << std::endl;
    delete i;
    delete u;

    return 0;

}