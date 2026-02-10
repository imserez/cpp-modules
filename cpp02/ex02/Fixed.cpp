#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int param)
{
    // std::cout << "Int constructor called" << std::endl;
    this->setRawBits(param << _fraction);
}

Fixed::Fixed(const float param)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(param * (1 << this->_fraction));
}

Fixed::~Fixed() {
    // std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        _value = obj.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &obj) const
{
    // std::cout << "Greater than operator called" << std::endl;
    return this->getRawBits() > obj.getRawBits();
}

bool Fixed::operator<(const Fixed &obj) const
{
    // std::cout << "Less than operator called" << std::endl;
    return this->getRawBits() < obj.getRawBits();
}

bool Fixed::operator>=(const Fixed &obj) const
{
    // std::cout << "Greater equal operator called" << std::endl;
    return this->getRawBits() >= obj.getRawBits();
}

bool Fixed::operator<=(const Fixed &obj) const
{
    // std::cout << "Less equal operator called" << std::endl;
    return this->getRawBits() <= obj.getRawBits();
}

bool Fixed::operator==(const Fixed &obj) const
{
    // std::cout << "Equal operator called" << std::endl;
    return this->getRawBits() == obj.getRawBits();
}

bool Fixed::operator!=(const Fixed &obj) const
{
    // std::cout << "Not equal operator called" << std::endl;
    return this->getRawBits() != obj.getRawBits();
}



Fixed& Fixed::operator++(void)
{
    this->_value++;
    return *this;
}

Fixed& Fixed::operator--(void)
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_value++;
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_value--;
    return (tmp);
}

Fixed Fixed::operator+(const Fixed &obj) const
{
    return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    return Fixed(this->toFloat() / obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    return Fixed(this->toFloat() * obj.toFloat());
}

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2)
{
    if (obj1 > obj2)
        return (obj2);
    else
        return (obj1);
}

const Fixed& Fixed::min(Fixed const &obj1, Fixed const &obj2)
{
    if (obj1 > obj2)
        return (obj2);
    else
        return (obj1);
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2)
{
    if (obj1 > obj2)
        return (obj1);
    else
        return (obj2);
}

const Fixed& Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
    if (obj1 > obj2)
        return (obj1);
    else
        return (obj2);
}



int Fixed::getRawBits(void) const
{
    return this->_value;
}

void    Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float   Fixed::toFloat(void) const
{
    float ret = (float)this->getRawBits() / (float)(1 << this->_fraction);
    return ret;
}

int     Fixed::toInt(void) const
{
    return (this->getRawBits() >> this->_fraction);
}

std::ostream    &operator<<(std::ostream &ostr, Fixed const &obj)
{
	ostr << obj.toFloat();
	return (ostr);
}