#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;
    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(32);
    mstack.push(511);
    mstack.push(672);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "-------------------------------------" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }


    std::cout << "-------------------------------------" << std::endl;
    std::cout << "-----------    LIST    --------------" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    std::stack<int> s(mstack);

    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::list<int>::iterator it2 = mlist.begin();
    std::list<int>::iterator ite2 = mlist.end();
    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    return 0;
}