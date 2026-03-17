#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: bad arguments, minimum 2" << std::endl;
        return 1;
    }

    PmergeMe themagic_is_here;
    try {
        themagic_is_here.run(argc, argv);
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}