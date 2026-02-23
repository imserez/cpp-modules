#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data test_data1;
    test_data1.id = 1;
    test_data1.name = "test1";

    Data *ptr1 = &test_data1;
    uintptr_t serialize_val = Serializer::serialize(ptr1);
    Data* deserialize_val = Serializer::deserialize(serialize_val);

    std::cout << "The memory address of Data* deserialize: " << deserialize_val << std::endl;
    std::cout << "The memory address of &test_data deserialize: " << ptr1 << std::endl;


    Data test_data2;
    test_data2.id = 2;
    test_data2.name = "test2";

    std::cout << "-------------------------------------" << std::endl;

    Data *ptr2 = &test_data2;
    uintptr_t serialize_val2 = Serializer::serialize(ptr2);
    Data* deserialize_val2 = Serializer::deserialize(serialize_val2);

    std::cout << "The memory address of Data* deserialize: " << deserialize_val2 << std::endl;
    std::cout << "The memory address of &test_data deserialize: " << ptr2 << std::endl;


    Data test_data3;
    test_data3.id = 2;  // testing with same id
    test_data3.name = "test3";

    std::cout << "-------------------------------------" << std::endl;

    Data *ptr3 = &test_data3;
    uintptr_t serialize_val3 = Serializer::serialize(ptr3);
    Data* deserialize_val3 = Serializer::deserialize(serialize_val3);

    std::cout << "The memory address of Data* deserialize: " << deserialize_val3 << std::endl;
    std::cout << "The memory address of &test_data deserialize: " << ptr3 << std::endl;
    return (0);
}
