#pragma once
#include <iostream>

class ScalarConverter {
    private:

    public:
        virtual ~ScalarConverter() = 0;

        static void convert(std::string literal);
};
