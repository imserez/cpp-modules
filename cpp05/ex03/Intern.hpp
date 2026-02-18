#pragma once

# include <iostream>
# include "AForm.hpp"

class Intern {
    private:

    public:
        Intern();
        ~Intern();
        Intern(const Intern &obj);
        Intern& operator=(const Intern &obj);
        
        AForm* makeForm(std::string formName, std::string targetForm);
    
    class InvalidName : public std::exception {
        public:
            virtual const char* what() const throw()
            {
                return "Invalid form request name";
            }

            std::string const details(const std::string value) const throw()
            {
                std::ostringstream oss;
                oss << "The name: " << value << " does not exist!";
                return oss.str();
            }
    };
};