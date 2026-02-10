#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:
        int                 _value;
        static const int    _fraction = 8;
    public:
        Fixed();
        Fixed(const Fixed &obj);
        Fixed& operator=(const Fixed &obj);
        ~Fixed();
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

};

#endif // fixed_hpp