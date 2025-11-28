#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal& other)
{
    *this = other;
    std::cout << "Animal copied" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Animal assigned" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructed" << std::endl;
}

std::string Animal::getType() const 
{
    return type;
}
