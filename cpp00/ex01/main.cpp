#include "Contact.hpp"
#include "PhoneBook.hpp"

# include <cstdlib>
# include <cctype>

static std::string getInput(std::string msg)
{
    std::string input = "";

    while (true)
    {
        std::cout << msg;
        if (!(std::getline(std::cin, input)))
            exit(0);
        if (!input.empty())
            return input;
        std::cout << "Field can't be empty" << std::endl;
    }
    return input;
}

static void    addNewContact(PhoneBook *phoneBook)
{
    std::string tmp_first_name = getInput("Enter first name: ");
    std::string tmp_last_name = getInput("Enter last name: ");
    std::string tmp_nickname = getInput("Enter nickname: ");
    std::string tmp_phone_number = getInput("Enter phone number: ");
    std::string tmp_darkest_secret = getInput("Enter darkest secret: ");
    phoneBook->addNewContact(Contact(tmp_first_name, tmp_last_name, tmp_nickname, tmp_phone_number, tmp_darkest_secret));
}

static void     searchContact(PhoneBook *phoneBook)
{
    std::string input_num;
    bool is_number = true;

    phoneBook->displayContacts();
    std::cout << "Enter contact index: ";
    if (!std::getline(std::cin, input_num))
            exit(0);
    if (input_num.empty())
        is_number = false;
    for (unsigned int i = 0; is_number && i < input_num.length(); i++)
    {
        if (!isdigit(input_num[i]))
            is_number = false;
    }
    if (is_number)
    {
        int index = std::atoi(input_num.c_str());
        if (index >= 0 && index < phoneBook->getContactsNum())
            phoneBook->displayContactInfo(index);
        else
            std::cout << "Invalid index: out of range." << std::endl;
    }
    else
        std::cout<< "Invalid index: must be numeric" << std::endl;
}

int main (void)
{
    PhoneBook phoneBook;
    std::string input;

    while (1)
    {
        std::cout << std::endl << "Type ADD to save a new contact, SEARCH to search for a contact or EXIT to exit the program" << std::endl;
		std::cout << "Enter command: ";
        if (!std::getline(std::cin, input))
            break;
        if (input.compare("ADD") == 0)
        {
            addNewContact(&phoneBook);
        }
        else if (input.compare("SEARCH") == 0)
        {
            if (phoneBook.getContactsNum() == 0)
                std::cout << "Empty contacts list" << std::endl;
            else
                searchContact(&phoneBook);
        }
        else if (input.compare("EXIT") == 0)
        {
            break;
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
    return 0;
}