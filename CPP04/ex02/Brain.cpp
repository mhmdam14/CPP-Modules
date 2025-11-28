#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain& other)
{
    *this = other;
    std::cout << "Brain copied" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructed";
}

std::string Brain::getIdea(int i) const
{
    if (i < 0 || i >= 100)
        throw std::out_of_range("Brain::getIdea() index out of bounds");
    return ideas[i];
}

void Brain::setIdea(int i, const std::string& idea)
{
    if (i < 0 || i >= 100)
        throw std::out_of_range("Brain::setIdea() index out of bounds");
    ideas[i] = idea;
}

