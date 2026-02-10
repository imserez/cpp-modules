#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) { 
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int param)
{
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(param << _fraction);
}

Fixed::Fixed(const float param)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(param * (1 << this->_fraction));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed& Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        _value = obj.getRawBits();
    return *this;
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