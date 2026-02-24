#include "ScalarConverter.hpp"
#include <iostream>

#include <sstream>
#include <limits>
#include <cctype>
#include <cstdlib>

#define ND 0
#define IM 1
#define NA 2
#define NF 3

static const std::string msg[] = {"Non displayable", "impossible", "nan", "nanf"};

static void print_all(std::string c_p, std::string i_p, std::string f_p, std::string d_p) {
    std::cout << "char: " << c_p << std::endl;
    std::cout << "int: " << i_p << std::endl;
    std::cout << "float: " << f_p << std::endl;
    std::cout << "double: " << d_p << std::endl;
}

void     ScalarConverter::convert(std::string literal) {
    
    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        print_all(msg[IM], msg[IM], literal + "f", literal);
        return;
    }

    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::string double_lit = literal.substr(0, literal.length() - 1);
        print_all(msg[IM], msg[IM], literal, double_lit);
        return;
    }

    char   c_val = 0;
    int    i_val = 0;
    float  f_val = 0.0f;
    double d_val = 0.0;

    if (literal.length() == 1 && !std::isdigit(literal[0])) 
    {
        c_val = literal[0];
        i_val = static_cast<int>(c_val);
        f_val = static_cast<float>(c_val);
        d_val = static_cast<double>(c_val);
    }
    else 
    {
        char* endPtr;
        d_val = std::strtod(literal.c_str(), &endPtr);
        if (*endPtr != '\0' && !(*endPtr == 'f' && *(endPtr + 1) == '\0')) {
            print_all(msg[IM], msg[IM], msg[IM], msg[IM]);
            return;
        }
        f_val = static_cast<float>(d_val);
        i_val = static_cast<int>(d_val);
        c_val = static_cast<char>(i_val);
    }
    std::string char_str;
    std::string int_str;
    std::string float_str;
    std::string double_str;

    if (d_val < 0 || d_val > 127) {
        char_str = msg[IM];
    } else if (!std::isprint(c_val)) {
        char_str = msg[ND];
    } else {
        char_str = "'";
        char_str += c_val;
        char_str += "'";
    }

    if (d_val < std::numeric_limits<int>::min() || d_val > std::numeric_limits<int>::max()) {
        int_str = msg[IM];
    } else {
        std::stringstream ss_i;
        ss_i << i_val;
        int_str = ss_i.str();
    }

    std::stringstream ss_f;
    std::stringstream ss_d;

    ss_f << f_val;
    ss_d << d_val;
    
    float_str = ss_f.str();
    double_str = ss_d.str();

    if (float_str.find('.') == std::string::npos && float_str != "inf" && float_str != "-inf") {
        float_str += ".0f";
    } else {
        float_str += "f"; 
    }

    if (double_str.find('.') == std::string::npos && double_str != "inf" && double_str != "-inf") {
        double_str += ".0";
    }
    print_all(char_str, int_str, float_str, double_str);
}
