#include "PhoneBook.hpp"

#include <iomanip>

PhoneBook::PhoneBook()
    : _contacts_num(0),
    _write_index(0)
{}

PhoneBook::~PhoneBook() {}


Contact PhoneBook::getContact(int id) const
{
    return _contacts[id];
}

std::string PhoneBook::_formatText(std::string text) const
{
    if (text.length() > 10)
        return (text.substr(0, 9) + '.');
    return (text);
}


void    PhoneBook::displayContacts() const
{
    int max = this->getContactsNum();
    std::cout << "|" << std::setw(10) << "Index" << "|"; 
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
    
    for(int i = 0; i < max; i++)
    {
        std::cout << "|" << std::setw(10) << i << "|";
        std::cout << std::setw(10) << _formatText(this->getContact(i).getFirstName()) << "|"; 
        std::cout << std::setw(10) << _formatText(this->getContact(i).getLastName()) << "|"; 
        std::cout << std::setw(10) << _formatText(this->getContact(i).getNickname()) << "|"; 
        std::cout << std::endl;
    }
}

void    PhoneBook::displayContactInfo(int id) const
{
    Contact contact = this->getContact(id);
    
    std::cout << std::endl;
    std::cout << "id: " << id << std::endl;
    std::cout << "First name: " << this->getContact(id).getFirstName() << std::endl;
    std::cout << "Last name: " << this->getContact(id).getLastName() << std::endl;
    std::cout << "Nickname: " << this->getContact(id).getNickname() << std::endl;
    std::cout << "Phone number: " << this->getContact(id).getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << this->getContact(id).getDarkestSecret() << std::endl;
}

void    PhoneBook::addNewContact(Contact new_contact)
{
    _contacts[_write_index] = new_contact;
    _write_index = (_write_index + 1) % MAX_CONTACTS;
    if (_contacts_num < MAX_CONTACTS)
        _contacts_num++;
}

int     PhoneBook::getContactsNum() const { return _contacts_num; }
