#pragma once

#include <string>

struct Data {

    int id;
    std::string name;

    Data();
    ~Data();
    Data(const Data &obj);
    Data& operator=(const Data &obj);
};
