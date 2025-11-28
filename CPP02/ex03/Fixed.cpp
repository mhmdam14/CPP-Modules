#include "Fixed.hpp"

Fixed::Fixed()
{
    number = 0;
}

Fixed::Fixed(const int n)
{
    number = n << bits;
}

Fixed::Fixed(const float f)
{
    number = roundf(f * (1 << bits));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}
Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->number = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
    return number;
}

void Fixed::setRawBits(const int raw)
{
    number = raw;
}

float Fixed::toFloat() const
{
    return (float)number / (1 << bits);
}

int Fixed::toInt() const
{
    return number >> bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->number > other.number);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->number < other.number);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->number >= other.number);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->number <= other.number);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->number == other.number);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->number != other.number);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    this->number++;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->number--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->number++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->number--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;    
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;    
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;    
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;    
}
