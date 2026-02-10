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
        ~Fixed();

        Fixed&  operator=(const Fixed &obj);
        bool    operator>(const Fixed &obj) const;
        bool    operator<(const Fixed &obj) const;
        bool    operator>=(const Fixed &obj) const;
        bool    operator<=(const Fixed &obj) const;
        bool    operator==(const Fixed &obj) const;
        bool    operator!=(const Fixed &obj) const;

        Fixed&  operator++(void);
        Fixed&  operator--(void);
        Fixed   operator++(int);
        Fixed   operator--(int);

        Fixed  operator*(const Fixed &obj) const;
        Fixed  operator/(const Fixed &obj) const;
        Fixed  operator-(const Fixed &obj) const;
        Fixed  operator+(const Fixed &obj) const;

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

        static Fixed& min(Fixed &obj1, Fixed &obj2);
        static const Fixed& min(Fixed const &obj1, Fixed const &obj2);

         static Fixed& max(Fixed &obj1, Fixed &obj2);
        static const Fixed& max(Fixed const &obj1, Fixed const &obj2);

};

std::ostream    &operator<<(std::ostream &ostr, Fixed const &obj);

#endif // fixed_hpp