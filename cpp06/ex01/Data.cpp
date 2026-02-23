#include "Data.hpp"

int id;
std::string name;

Data::Data() : id(0), name("default") {};
Data::~Data() {};
Data::Data(const Data &obj) : id(obj.id), name(obj.name) {};
Data& Data::operator=(const Data &obj)
{
    if (this != &obj)
    {
        id = obj.id;
        this->name = obj.name;
    }
    return *this;
}
