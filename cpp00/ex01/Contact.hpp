#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class	Contact
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
    public:
        Contact();
        ~Contact();
        Contact(std::string first_name, std::string last_name, std::string nickname,
            std::string phone_number, std::string darkest_secret);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif