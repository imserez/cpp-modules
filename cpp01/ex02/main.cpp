#include <iostream>


int main(void)
{
	std::string phrase = "HI THIS IS BRAIN";

	std::string	*stringPTR = &phrase;
	std::string &stringREF = phrase;

	std::cout << "Memory add. of string value: " << &phrase << std::endl;
	std::cout << "Memory add. of string stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory add. of string stringREF: " << &stringREF << std::endl;

	std::cout << "Value of string value: " << phrase << std::endl;
	std::cout << "Value of string stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of string stringREF: " << stringREF << std::endl;


	return 0;
}
