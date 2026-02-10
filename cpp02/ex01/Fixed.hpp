#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <ostream>

class Fixed
{
    private:
        int                 _value;
        static const int    _fraction = 8;
    public:
        Fixed();
        Fixed(const Fixed &obj);
        Fixed(const int param);
        Fixed(const float param);
        Fixed& operator=(const Fixed &obj);
        ~Fixed();
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

};

std::ostream    &operator<<(std::ostream &ostr, Fixed const &obj);

#endif // fixed_hpp