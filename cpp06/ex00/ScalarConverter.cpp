#include "ScalarConverter.hpp"
#include <iostream>

#define ND 0
#define IM 1
#define NA 2
#define NF 3

std::string msg[] = {"Non displayable", "Impossible", "nan", "nanf"};

static void    print_all(std::string c_p, std::string i_p, std::string f_p, std::string d_p) {
    std::cout << "char: " << c_p << std::endl;
    std::cout << "char: " << i_p << std::endl;
    std::cout << "char: " << f_p << std::endl;
    std::cout << "char: " << d_p << std::endl;
}

void     ScalarConverter::convert(std::string literal) {
    if (literal == "nan" || literal == "nanf" || literal.length() <= 0) {
        print_all(msg[IM], msg[IM], msg[NA], msg[NF]);
        return;
    }
    std::string char_print;

    if (literal.length() > 1)
    {
        //TODO: check for chars like \n
        char_print = msg[IM];
    }
    else if (literal[0] - '0' < 32 || literal[0] - '0' > 126)
        char_print = msg[ND];
    else
        char_print = literal;

    print_all(char_print, char_print ,char_print ,char_print);
}
