#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void);
void identify(Base& p);
void identify(Base* p);

Base* generate(void)
{
    int randomNum = rand() % 3;
    switch(randomNum) {
        case 0:
            return new A;
            break;
        case 1:
            return new B;
            break;
        case 2:
            return new C;
            break;
        default:
            std::cout << "Error during number generation, number =" << randomNum << std::endl;
            return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
         std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p))
    {
         std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p))
    {
         std::cout << "C" << std::endl;
    } else
    {
         std::cout << "Unknown Base type pointer" << std::endl;
    }
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
        return;
	}
	catch (std::exception &e) { }
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
        return;
	}
	catch (std::exception &e) { }
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
        return;
	}
	catch (std::exception &e) { }
    std::cout << "Unknown Base type ref." << std::endl;
}


int main(void)
{
    srand(time(0));

    Base* gen1 = generate();
    Base* gen2 = generate();
    Base* gen3 = generate();
    Base* gen4 = generate();

    identify(gen1);
    identify(gen2);
    identify(gen3);
    identify(gen4);

    std::cout << " ---------------------------------- " << std::endl;

    identify((*gen1));
    identify((*gen2));
    identify((*gen3));
    identify((*gen4));

    delete gen1;
    delete gen2;
    delete gen3;
    delete gen4;
    return (0);
}
