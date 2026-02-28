#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    std::srand(std::time(0));

    std::cout << "-------------------------------------" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;

    std::cout << "------------ 10000 --------------------" << std::endl;
    Span bigSpan(10000);
    std::vector<int> bigVector;
    for (int i = 0; i < 10000; ++i) {
        bigVector.push_back(std::rand());
    }

    try {
        bigSpan.addNumbers(bigVector.begin(), bigVector.end());
        std::cout << "10000 added" << std::endl;
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---------------Errors-----------------" << std::endl;
    try {
        Span smallSpan(1);
        smallSpan.addNumber(42);
        smallSpan.addNumber(43);
    } catch (const std::exception& e) {
        std::cout << "error : " << e.what() << std::endl;
    }

    try {
        Span emptySpan(5);
        emptySpan.addNumber(10);
        emptySpan.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "error : " << e.what() << std::endl;
    }

    return 0;
}