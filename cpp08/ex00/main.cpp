#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {

    std::vector<int> numbers;
    numbers.push_back(123123);
    numbers.push_back(45554545);
    numbers.push_back(4545554);
    numbers.push_back(42);

    std::cout << "-------------------------------------" << std::endl;
    try {
        int n1 = 42;
        std::cout << n1 << std::endl;
        std::vector<int>::iterator it = easyfind(numbers, n1);
        std::cout << "Value found: " << *it << std::endl;
        std::cout << "-------------------------------------" << std::endl;

        int n2 = 5235;
        std::cout << n2 << std::endl;
        easyfind(numbers, n2);
        std::cout << "Value found: " << *it << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}