#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# define MAX_CONTACTS 8

# include "Contact.hpp"
# include <iostream>

class PhoneBook 
{
    private:
        Contact _contacts[MAX_CONTACTS];
        int _contacts_num;
        int _write_index;
        std::string _formatText(std::string text) const;
    public:
        PhoneBook();
        ~PhoneBook();
        
        Contact getContact(int id) const;
        void    displayContacts() const;
        void    displayContactInfo(int id) const;
        void    addNewContact(Contact new_contact);
        int     getContactsNum() const;
};

#endif