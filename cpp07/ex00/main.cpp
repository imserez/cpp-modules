#include "whatever.hpp"


#include <iostream>


int main(void)
{

    int obj1 = 10;
    int obj2 = 20;


    std::cout << "BEFORE SWAP" << std::endl;
    std::cout << "obj1: " << obj1 << " obj2: " << obj2 << std::endl;
    ::swap(obj1, obj2);
    std::cout << "AFTER SWAP" << std::endl;
    std::cout << "obj1: " << obj1 << " obj2: " << obj2 << std::endl;

    std::cout << "MIN: " << ::min(obj1, obj2) << std::endl;
    std::cout << "MAX: " << ::max(obj1, obj2) << std::endl;
    std::cout << "-------------------- SUBJECT TESTS: " << std::endl;


    int a = 2;
    int b = 3; 
    ::swap(a,b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b ) = " << ::min(a,b) << std::endl;
    std::cout << "max(a, b ) = " << ::max(a,b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c,d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d ) = " << ::min(c,d) << std::endl;
    std::cout << "max(c, d ) = " << ::max(c,d) << std::endl;

    return 0;
}